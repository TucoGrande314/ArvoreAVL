template<class T>
NoArvore<T>::NoArvore()
{
	info = NULL;
	esquerdo = NULL;
	direito = NULL;
}

template<class T>
NoArvore<T>::NoArvore(T i)
{
	info = i;
	esquerdo = NULL;
	direito = NULL;
}

template<class T>
NoArvore<T>::NoArvore(const NoArvore<T>& no)
{
    this->info = no.info;
    if(no.esquerdo != NULL)
        this->esquerdo = new NoArvore(*no.esquerdo);
    if(no.direito != NULL)
        this->direito = new NoArvore(*no.direito);
}

template<class T>
NoArvore<T>::~NoArvore()
{
}

template<class T>
T NoArvore<T>::getInfo()
{
	return info;
}
