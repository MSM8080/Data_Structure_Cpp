#include "matrix.h"
#include <cmath>
#include <ctime>
Matrix::Matrix( int rows_, int cols_)
: rows(rows_), cols(cols_)
{
    data = new float*[rows];
    for(int i=0;i<rows;i++)
    {
        data[i] = new float[cols];
    }

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            data[i][j]=0;
        }
    }
}

Matrix::Matrix(int rows_, int cols_, float val)
: rows(rows_), cols(cols_)
{
    data = new float*[rows];
    for(int i=0;i<rows;i++)
    {
        data[i] = new float[cols];
    }

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            data[i][j]=val;
        }
    }
}

Matrix::Matrix(int rows_, int cols_, MatrixType m_type)
: rows(rows_), cols(cols_)
{
    data = new float*[rows];
    for(int i=0;i<rows;i++)
    {
        data[i] = new float[cols];
    }

    srand(time(NULL)); // srand take time of pc as random seed

    if(m_type == Random) // Random =1
    {
        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                data[i][j] = rand(); // evolute random number from seed
            }
        }
    }
    else if(m_type == Identity) // Identity = 0
    {
         for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(i==j)
                    data[i][j]=1;
                else
                    data[i][j]=0;
            }
        }
    }
}

/*Copy constructor: to prevent shallow copy*/
Matrix::Matrix(const Matrix& m)
{}

Matrix::~Matrix()
{}

int Matrix::get_rows() const
{
    int c;
    c = rows;
    return c;
}

int Matrix::get_cols() const
{
    int c;
    c = cols;
    return c;
}

void Matrix::print() const
{
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

float& Matrix::operator()(int r_ind, int c_ind)
{
    for(int i =0;i<rows;i++)
    {
        if(i==r_ind)
        {
            for(int j=0;j<cols;j++)
            {
                if(j==c_ind)
                {
                    return data[i][j];
                }
            }
        }
    }
}


float& Matrix::access(int r_ind, int c_ind)
{
    for(int i =0;i<rows;i++)
    {
        if(i==r_ind)
        {
            for(int j=0;j<cols;j++)
            {
                if(j==c_ind)
                {
                    return data[i][j];
                }
            }
        }
    }
}

Matrix Matrix::operator+(const Matrix& m) const
{
    Matrix R(rows,cols);
    if(rows!=m.rows || cols!=m.cols)
    {
        cout<<"must same size !!"<<endl;
        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                R.data[i][j]=0;
            }
        }
        return R;
    }


    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            R.data[i][j]=data[i][j]+m.data[i][j];
        }
    }
    return R;
}

Matrix Matrix::operator-(const Matrix& m) const
{
    Matrix R(rows,cols);

    if(rows!=m.rows || cols!=m.cols)
    {
        cout<<"must same size !!"<<endl;
        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                R.data[i][j]=0;
            }
        }
        return R;
    }

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            R.access(i,j)=data[i][j]-m.data[i][j];
        }
    }
    return R;
}

Matrix Matrix::operator*(float val) const
{
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            data[i][j]*=5;
        }
    }
}

Matrix Matrix::operator/(float val) const
{
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            data[i][j]/=5;
        }
    }
}

Matrix Matrix::operator*(const Matrix& m) const
{
    Matrix R(rows,cols);

    if(rows!=m.rows || cols!=m.cols)
    {
        cout<<"must same size !!"<<endl;
        for(int i =0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                R.data[i][j]=0;
            }
        }
        return R;
    }

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            R.access(i,j)=data[i][j]*m.data[j][i];
        }
    }
    return R;
}

Matrix Matrix::operator/(const Matrix& m) const
{}

bool Matrix::operator==(const Matrix& m) const
{
    bool status;
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]==m.data[i][j])
                status = true;
            else
                status = false;
        }
    }
    return status;
}

bool Matrix::operator!=(const Matrix& m) const
{
    bool status;
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]!=m.data[i][j])
                status = true;
            else
                status = false;
        }
    }
    return status;
}

bool Matrix::isIdentity() const
{
    bool status;
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==j && data[i][j]==1)
                status = true;
            else if(i!=j && data[i][j]==0)
                status = true;
            else
                status = false;
        }
    }
    return status;
}

bool Matrix::isIdempotent() const
{
    bool status;
    Matrix R(rows,cols);
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            R.access(i,j)=data[i][j]*data[j][i];
        }
    }
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(R.data[i][j]==data[i][j])
                status = true;
            else
                status = false;
        }
    }
    return status;
}

bool Matrix::isSquare() const
{
    if(rows==cols)
        return 1;
    else
        return 0;
}

bool Matrix::isSymmetric() const
{
    bool status;

    if(rows!=cols)
        return 0;

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]==data[j][i])
                status = true;
            else
            {
                return 0;
            }
        }
    }
    return status;
}

bool Matrix::isUpperTriangle() const
{
    bool status;

    if(rows!=cols)
        return 0;

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(j<i)
            {
                if(data[i][j]==0)
                    status = true;
                else
                {
                    return 0;
                }
            }
        }
    }
    return status;
}

bool Matrix::isLowerTriangle() const
{
    bool status;

    if(rows!=cols)
        return 0;

    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(j>i)
            {
                if(data[i][j]==0)
                    status = true;
                else
                {
                    return 0;
                }
            }
        }
    }
    return status;
}

Matrix Matrix::transpose() const
{
    Matrix R(cols,rows);
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            R.data[j][i]=data[i][j];
        }
    }
    return R;
}

void Matrix::fill(float val)
{
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            data[i][j]=val;
        }
    }
}

float Matrix::minElement() const
{
    float mi=data[0][0];
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]<mi)
                mi=data[i][j];
        }
    }
    return mi;
}

float Matrix::maxElement() const
{
    float ma=data[0][0];
    for(int i =0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(data[i][j]>ma)
                ma=data[i][j];
        }
    }
    return ma;
}

float Matrix::determinant() const
{}

string Matrix::toString() const
{return string("");}
