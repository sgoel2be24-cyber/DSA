#include <iostream>
using namespace std;

struct Triplet
{
    int row, col, val;
};

class Sparse
{
    int m, n, num;
    Triplet *a;

public:
    Sparse(int rows, int cols, int nonZero)
    {
        m = rows;
        n = cols;
        num = nonZero;
        a = new Triplet[num];
        cout << "enter row col value:" << endl;
        for (int i = 0; i < num; i++)
        {
            cin >> a[i].row >> a[i].col >> a[i].val;
        }
    }

    void show()
    {
        for (int i = 0; i < num; i++)
            cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    }

    Sparse transpose()
    {
        Sparse t(n, m, num);
        for (int i = 0; i < num; i++)
        {
            t.a[i].row = a[i].col;
            t.a[i].col = a[i].row;
            t.a[i].val = a[i].val;
        }
        return t;
    }

    Sparse add(Sparse &b)
    {
        Sparse sum(m, n, 0);
        sum.a = new Triplet[num + b.num];
        int i = 0, j = 0, k = 0;

        while (i < num && j < b.num)
        {
            if (a[i].row < b.a[j].row ||
                (a[i].row == b.a[j].row && a[i].col < b.a[j].col))
                sum.a[k++] = a[i++];
            else if (a[i].row > b.a[j].row ||
                     (a[i].row == b.a[j].row && a[i].col > b.a[j].col))
                sum.a[k++] = b.a[j++];
            else
            {
                a[i].val += b.a[j].val;
                if (a[i].val != 0)
                    sum.a[k++] = a[i];
                i++;
                j++;
            }
        }
        while (i < num)
            sum.a[k++] = a[i++];
        while (j < b.num)
            sum.a[k++] = b.a[j++];
        sum.num = k;
        return sum;
    }

    Sparse multiply(Sparse &b)
    {
        if (n != b.m)
            return Sparse(0, 0, 0);
        Sparse prod(m, b.n, 0);
        prod.a = new Triplet[num * b.num];
        int k = 0;

        for (int i = 0; i < num; i++)
            for (int j = 0; j < b.num; j++)
                if (a[i].col == b.a[j].row)
                {
                    prod.a[k].row = a[i].row;
                    prod.a[k].col = b.a[j].col;
                    prod.a[k].val = a[i].val * b.a[j].val;
                    k++;
                }
        prod.num = k;
        return prod;
    }
};

int main()
{
    int m, n, num;
    cout << "enter rows cols non-zero elements: ";
    cin >> m >> n >> num;
    Sparse s1(m, n, num);
    cout << "matrix is:" << endl;
    s1.show();

    Sparse t = s1.transpose();
    cout << "transposed:" << endl;
    t.show();

    cout << "enter second matrix for addition:" << endl;
    int m2, n2, num2;
    cin >> m2 >> n2 >> num2;
    Sparse s2(m2, n2, num2);
    Sparse sum = s1.add(s2);
    cout << "sum is:" << endl;
    sum.show();

    cout << "enter second matrix for multiplication:" << endl;
    cin >> m2 >> n2 >> num2;
    Sparse s3(m2, n2, num2);
    Sparse prod = s1.multiply(s3);
    cout << "product is:" << endl;
    prod.show();
    return 0;
}
