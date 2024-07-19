//Assingment problem statement 1 
//By AnushDighore
//CE-2ndYear-B.28

#include<iostream>
using namespace std;

class Matrix {
    int row = 0;
    int col = 0;
    
    static const int rMax=100 ;
    static const int cMax=100 ;
    int arr[rMax][cMax] ;

    public:
        // Constructors
        Matrix();
        Matrix(int,int);
        Matrix(Matrix &m2); 

         // Member functions
        void read();
        void display();
        void getRow();
        void getCol();
        void setElement(int,int);
        void add(Matrix);
        void multiply(Matrix);
        void Trans(Matrix);
};

Matrix :: Matrix(){
    row=0;
    col=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j]= 0;
        }
    }
}

Matrix :: Matrix(int r, int c){
    row = r;
    col = c;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j]= 0;
        }
    }
}

Matrix :: Matrix(Matrix &m2){
    row= m2.row;
    col= m2.col;
    
    for(int i=0; i<row; i++){ 
        for(int j=0; j<col; j++){
            arr[i][j]= m2.arr[i][j];
        }
    }
}

void Matrix :: read(){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }
}

void Matrix :: display(){
    for (int i=0; i<row; i++){
        for (int j=0; j<col; j++){
            cout<<" "<<arr[i][j];
        }cout<<endl;
    }
}

void Matrix :: getRow(){
    cout<<"Row : "<<row<<endl;
}

void Matrix :: getCol(){
    cout<<"Col : "<<col<<endl;
}

void Matrix :: setElement(int r, int c){
    cout<<"enter value : ";
    cin>>arr[r][c];
}

void Matrix :: add(Matrix m2){
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            arr[i][j]+= m2.arr[i][j];
        }
    }
}

void Matrix :: multiply(Matrix m2){

    for(int i=0; i<row; i++) {
        for(int j=0; j<m2.col; j++) {
            for(int k=0; k<col; k++) {
                arr[i][j] += arr[i][k] * m2.arr[k][j];
            }
        }
    }
}

void Matrix :: Trans( Matrix m2) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[j][i] =m2.arr[i][j];  
        }
    }
}

int main() {
    
    static const int max = 10;
    Matrix mat[max];
    Matrix temp(2,2);
    int n =-1;
    int temp1,temp2;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Matrix\n";
        cout << "2. Copy Matrix\n";
        cout << "3. Display Matrix\n";
        cout << "4. Transpose Matrix\n";
        cout << "5. Add Matrix\n";
        cout << "6. Multiply Matrix\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                n++;
                mat[n] = Matrix(2,2);
                cout<<" Enter "<<n+1 <<"th Matrix elements : ";
                mat[n].read();
                cout<<"  "<<n+1<<"th Matrix created !"<<endl;
                break;

            case 2:
                if (n == -1){
                    cout<<"Error!\n";
                    break;            
                }
                cout<<" There are "<<n+1<<" Matrix"<<endl;
                n++;
                mat[n] = Matrix(2,2);
                cout<<"  Which matrix do you want to copy: ";
                cin>>temp1;
                if (temp1 != 0 && temp1<= n+1){
                    mat[n]=mat[temp1-1];
                     cout<<"   "<<n+1<<"th Matrix created !"<<endl;
                }
                else cout<<"   Error!\n"; 
                break;

            case 3:
                if (n==-1) {
                    cout << "No employees found." << endl;
                    break;
                }
                cout << "Matrix Details:" << endl<<endl;
                for (int i=0;i<=n; i++) {
                    cout<<"["<<i+1<<"th] Matrix :\n";
                    mat[i].display();
                    cout << endl;
                }
                break;

            case 4:
                if (n == -1){
                    cout<<"Error!\n";
                    break;            
                }
                cout<<" Which matrix do you want to Transpose : ";
                cin>>temp1;
                temp.Trans(mat[temp1-1]);
                cout<<" resultant : \n";
                temp.display();
                break;

            case 5:
                if (n == -1){
                    cout<<"Error!\n";
                    break;            
                }
                cout<<" Which matrix do you want to add with which : ";
                cin>>temp1>>temp2;
                temp = mat[temp1-1];
                temp.add(mat[temp2-1]);
                cout<<" resultant : \n";
                temp.display();
                break;

            case 6:
                if (n == -1){
                    cout<<"Error!\n";
                    break;            
                }
                cout<<" Which matrix do you want to Multiply with which : ";
                cin>>temp1>>temp2;
                temp= mat[temp1-1];
                temp.multiply(mat[temp2-1]);
                cout<<" resultant : \n";
                temp.display();
                break;

            case 7: 
                cout << "Exiting program." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
    
    
    return 0;
}
