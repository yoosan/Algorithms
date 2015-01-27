@@ -0,0 +1,178 @@
//
//  main.cpp
//  Matrix
//
//  Created by zhou on 1/1/15.
//  Copyright (c) 2015 Dimen. All rights reserved.
//

#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
    //static const int Max_Size = 1000;
    
    int row;
    int column;
    
    T **twoDimenArray;
    
public:
    explicit Matrix (int row, int column) {           //Constructor of Matrix
        this ->row = row;
        this ->column = column;
        
        if (row <= 0 || column <= 0)
        {
            cout << "Row or Column invaild." << endl;
            return;
        }
        
        twoDimenArray = new T *[row];
        for (int i = 0;i < row; i++)
            twoDimenArray[i] = new T[column];
    };
    
    explicit Matrix (const Matrix &ref){             //Deep Copy constructor of Matrix.
        this ->row = ref.row;
        this ->column = ref.column;
        
        this -> twoDimenArray = new T *[this->row];
        for (int i = 0; i < this->row; i++)
            this -> twoDimenArray[i] = new T[this->column];
        
        for (int i = 0; i < this->row; i++)
            for(int j = 0; j < this->column; j++)
                this -> twoDimenArray[i][j] = ref.twoDimenArray[i][j];
    }
    
    virtual ~Matrix ()                               //Destructor of Matrix
    {
        for (int i = 0; i < row; i++)
            delete [] twoDimenArray[i];
        //cout << "Destructor Successfule!" <<endl;
    }
    
    
    bool createMartix()                               //Create a Matrix
    {
        if (row <= 0 || column <= 0)
            return false;
        cout << "Please input the martix by first row then column." <<endl;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                cin >> twoDimenArray[i][j];
        return true;
    }
    
    bool disPlay()                                    //Show the matrix by row first.
    {
        if(row <= 0 || column <= 0)
            return false;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                cout << twoDimenArray[i][j] << " ";
            cout << endl;
        }
        return true;
    }
    
    Matrix& operator= (const Matrix<T> &ref)            //Override the operator =
    {
        this -> row = ref.row;
        this -> column = ref.column;
        
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->column; j++)
                this -> twoDimenArray[i][j] = ref.twoDimenArrar[i][j];
        return *this;
    }
    
    Matrix& operator+ (const Matrix<T> &ref)            //Override the operator +
    {
        if (this->row != ref.row || this->column != ref.column)
            cout << "Error: They are not the same row and column. "<< endl;
        
        //Matrix<T> temp(ref.row, ref.column);
        
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j< this->column; j++)
                this -> twoDimenArray[i][j] += ref.twoDimenArray[i][j];
        return *this;
    }
    
    Matrix& operator- (const Matrix<T> &ref)           //Override the operator -
    {
        if (this->row != ref.row || this->column != ref.column)
            cout << "Error: They are not the same row and column. "<< endl;
        
        for (int i = 0; i < row ; i++)
            for (int j = 0; j < column; j++)
                this -> twoDimenArray[i][j] += ref.twoDimenArray[i][j];
        return *this;
    }
    
    Matrix& operator- ()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
                this->twoDimenArray[i][j] *= -1;
        return *this;
    }
    
    
    Matrix& operator* (const Matrix<T> &ref)           //Override the operator *
    {
        if (this -> column != ref.row)
        {
            cout << "Error: Two Matrics which the first's column not equal to the second's row cant be multipy";
        }
        
        int column = this -> column;;
        this -> column = ref.column;
        for (int i = 0; i < this -> row; i++)
        {
            for(int j = 0; j < ref.column; j++)
            {
                T temp = 0;
                for (int k = 0; k < column; k++)
                {
                    temp += this->twoDimenArray[i][k] * ref.twoDimenArray[k][j];
                }
                this -> twoDimenArray[i][j] = temp;
            }
        }
        return *this;
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    
    Matrix<int> test(2, 4);
    
    test.createMartix();
    
    test.disPlay();
    
    Matrix<int> mu(4, 2);
    
    mu.createMartix();
    
    mu.disPlay();
    
    (test * mu).disPlay();
    
    //Matrix<int> an(test);
    //an.disPlay();
    
    //(test + an).disPlay();
    
    //(-test).disPlay();
    
    
    return 0;
}
