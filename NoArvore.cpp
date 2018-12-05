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
NoArvore<T>::~NoArvore()
{
}

template<class T>
T NoArvore<T>::getInfo()
{
	return info;
}

template<class T>
void NoArvore<T>::setInfo(T i)
{
	this->info = i;
}


template<class T>
bool NoArvore<T>::ehFolha()
{
	if(this->esquerdo != NULL)
		return false;
	if(this->direito != NULL)
		return false;

	return true;
}

template<class T>
void NoArvore<T>::excluir(T i)
{
	if(i > this->info)
		this->direito->excluir(i);
	else
	if(i < this->info)
		this->esquerdo->excluir(i);
	else
	{
		if(this->esquerdo != NULL )
		{
			T aux = this->info;
			this->info = this->esquerdo->info;
			this->esquerdo->info = aux;
			if(this->esquerdo->ehFolha())
				delete this->esquerdo;
			else
				this->esquerdo->excluir(T); 
		}
		else
		if(this->direito != NULL)
		{
			T T aux = this->info;
			this->info = this->direito->info;
			this->direito->info = aux;

			if(this->direito->ehFolha())
				delete this->direito;
			else
				this->direito->excluir(T);
		}
	}

}
