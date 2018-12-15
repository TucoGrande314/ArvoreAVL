#ifndef NOARVORE_H
#define NOARVORE_H

template<class T>
class NoArvore
{
    public:
        NoArvore();
        NoArvore(T);
        NoArvore(const NoArvore<T>&);
        ~NoArvore();

        NoArvore<T>* esquerdo;
        NoArvore<T>* direito;

        T getInfo();
        //void setInfo(T);


    private:
        T info;
};

#include "NoArvore.inl"
#endif // NOARVORE_H
