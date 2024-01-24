#include<bits/stdc++.h>
#include<fstream>
using namespace std;
class Inode{
private:
     string address="C:\\Users\\dell\\cpp traning\\File-Stystem\\inodes";
public:
    void insert(string filename){
        ofstream onfile;
        onfile.open(address,ios::app);
        if(!onfile.is_open()){
            cout<<"Error Inodes file not opened 1"<<endl;
            return;
        }
        onfile<<filename<<" ";
        onfile.close();
    }
    int iscontainskey(string filename){
        ifstream infile;
        infile.open(address);
        if(!infile.is_open()){
            cout<<"Error Inodes file not opened 2"<<endl;
            return -1;
        }
        string temp;
        while(getline(infile,temp,' ')){
            if(temp==filename){
                infile.close();
                return 1;
                }
        }
        infile.close();

        return 0;
    }

};
class file{
    private:
    string address="C:\\Users\\dell\\cpp traning\\File-Stystem\\";
    public:

//    **** to create the indoes file use to store metadata ******
    void creat_indoes(){
        ofstream onfile;
        onfile.open(address+"inodes");
        onfile.close();
        cout<<"Inodes created"<<endl;
   }

   //   **** To create a new file **** 
     void create(){
        Inode obj;
        cout<<"Enter File Name :"<<endl;
        string filename;
        cin>>filename;
        int num=obj.iscontainskey(filename);
        if(num==1){
            cout<<"File name already exists "<<endl;
            return ;
        }
        else if(num==0){
            obj.insert(filename);
            cout<<"New File is created : "<<filename<<endl;
        }
     }

//  *************To insert data into the existing file********
     void insert(){
        cout<<"Enter file name in which you want to add data"<<endl;
        string filename;
        cin>>filename;
        Inode obj;
        int num=obj.iscontainskey(filename);
        if(num==0){
            cout<<"Such File Name not exists"<<endl;
            return ;
        }
        else if(num==-1){
            return ;
        }
            ofstream onfile;
            onfile.open(address+filename,ios::app);
            if(!onfile.is_open()){
                cout<<"Error file not opened "<<filename<<endl;
                return ;
            }
            cout<<"Enter data you want to store in file "<< filename<<endl;
            string temp;
             cin>>temp;
             onfile<<"This is the data for my first file"<<endl;
            onfile.close();
            cout<<"Data is inserted successfylly"<<endl;
        
     }

   // ********** read function ****************
     void read(){
        string filename;
        cout<<"Enter File Name from which you want to extract data "<<endl;
        cin>>filename;
        Inode obj;
        int num=obj.iscontainskey(filename);
        if(num==0 || num==-1){
            cout<<"File not found : "<<filename<<endl;
        }
        else{
            cout<<"Data is :"<<endl;
            ifstream infile;
            infile.open(address+filename);
            string temp;
            while(getline(infile,temp)){
                cout<<temp;
                cout<<endl;
            }
            infile.close();
        }
     }

     void update(){
        cout<<"Enter File Name for which you want updation"<<endl;
        string filename;
        cin>>filename;
        Inode obj;
        int num=obj.iscontainskey(filename);
        if(num==0 || num==-1){
            cout<<"File Not exists"<<endl;
        }
        else{
             
        }

     }
     // ****    delete ******

     void delee(){
          Inode obj;
          cout<<"Enter filename you want to delete"<<endl;
          string filename;
          cin>>filename;
          fstream file(address+"inodes");
          if(!file.is_open()){
          cout<<"Error File not opened "<<endl;
          return;
        }
        string temp="";
        // ofstream onfile;
        // onfile.open(address+"Inodes",ios::app);
        while(getline(file,temp)){
            auto  pos = temp.find(filename);
                if(pos!=string::npos){
                        // If found, move the file pointer to the beginning of the line to overwrite it
                        file.seekp(file.tellg() - static_cast<streampos>(temp.length()) - 1);

                        // Replace the line with spaces or empty string to "delete" it
                        file << string(temp.length(),' ');

                        // Move the file pointer back to where it was
                        file.seekp(file.tellg());
                        cout<<"File Deleted "<<endl;
                        return;
              }
        }
        
            cout<<"No such file exists"<<endl;
            return ;
        

     }
     //*********   to give  all file name
    void display_file_name(){
        ifstream infile;
        infile.open(address+"inodes");
        // infile.close();  to check if somehow file not opened 
        if(!infile.is_open()){
          cout<<"Error File not opened "<<endl;
          return;
        }
        string s="";
        cout<<"All Files Name are : "<<endl;
        while(getline(infile,s,' ')){
            cout<<s<<endl;
        }
        infile.close();
    }
};
int main(){
    cout<<"Enter 2 to create new file "<<endl;
    cout<<"Enter 3 to insert data in a file "<<endl;
    cout<<"Enter 4 to read data from the file "<<endl;
    cout<<"Enter 5 to display names of all file "<<endl;
    cout<<"Enter 6 to delete the file "<<endl;
    int n ;
    cin>>n;
    file obj;
    switch (n)
    {
    case 11:
        obj.creat_indoes();
        break;
    case 2:
        obj.create();
        break;
    case 3:
        obj.insert();
        break;
    case 4:
        obj.read();
        break;
    case 5:
        obj.display_file_name();
        break;
    case 6:
        obj.delee();
        break;
    default:
        cout<<"Invalid command"<<endl;
        break;
    }
      
   

return 0;
}