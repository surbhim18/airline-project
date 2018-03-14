#ifndef PNODE_H
#define PNODE_H


class Pnode
{
    private:
        int tktNo;
        char* pname;
        int age;
        char gender;

    public:
        Pnode* next;
        const char* getPname() const;
        const int getTktNo() const;
        Pnode(int);
        Pnode(const Pnode&);
        void enterN();
        void displayN() const;
        ~Pnode();

};

#endif // PNODE_H
