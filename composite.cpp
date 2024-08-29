#include<iostream>
#include<vector>

using namespace std;

class FilesystemEntity{
public:
    virtual void display(int) = 0;
    virtual void add(FilesystemEntity*) {} ;
    virtual ~FilesystemEntity() = default; 
};

class File : public FilesystemEntity {
private:
    string name;
public:
    File(string name) : name(name) {};
    void display(int indentation=0) override {
        for(int i=0;i<indentation;i++){
            cout<<" ";
        }
        cout<<"-"<<name<<endl;
    }
};

class Directory: public FilesystemEntity {
private:
    string name;
    vector<FilesystemEntity*>childs;
public:
    Directory(string name) : name(name) {};

    void add(FilesystemEntity* child) override {
        childs.push_back(child);
    }

    void display(int indentation =0){
        for(int i=0;i<indentation;i++)
            cout<<" ";
        cout<<"+"<<name<<endl;
        for(int i=0;i<childs.size();i++)
            childs[i]->display(indentation+1);
    }
};

int main() {
    Directory *d1 = new Directory("dir1");
    Directory *d2 = new Directory("dir2");
    Directory *d3 = new Directory("dir3");

    File *f1 = new File("file1");
    File *f2 = new File("file2");
    File *f3 = new File("file3");

    d1->add(f3);
    d1->add(d2);
    d2->add(f2);
    d1->add(d3);
    d3->add(f3);

    d1->display();

    delete d1, f1, d2, f2, d3, f3;
}