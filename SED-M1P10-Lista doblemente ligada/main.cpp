#include <iostream>
#include "socio.hpp"


template<class T>
class LDLLSE;

template<class T>
class nodo{
private:
    T data;
    nodo<T>* sig;
    nodo<T>* ant;
public:
    nodo():sig(nullptr), ant(nullptr){};
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    nodo<T>* ancla;
public:
    LDLLSE(): ancla(nullptr){};
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, T elem);
    bool elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, T elem){
    nodo<T>* aux= new nodo<T>;
    aux->data=elem;

    if(pos==nullptr) {
        aux->ant=nullptr;
        aux->sig=ancla;
        if(ancla!=nullptr)
            ancla->ant = aux;
        ancla=aux;
        }
    else {
        aux->ant=pos;
        aux->sig=pos->sig;
        if(pos->sig!=nullptr)
            pos->sig->ant=aux;
        pos->sig=aux;
        }

}

template<class T>
bool LDLLSE<T>::elimina(nodo<T>* pos){
   if(vacia() || pos==nullptr) {
        return false;
        }

    if(pos->ant != nullptr)
        pos->ant->sig=pos->sig;

    if(pos->sig !=nullptr)
        pos->sig->ant = pos->ant;

    if(pos==ancla) {
        ancla=ancla->sig;
        }

    delete pos;
    return true;
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia()){
        return ancla;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    if(vacia()){
        return nullptr;
    }
    else{
        nodo<T>* aux=ancla;
        while(aux!=nullptr && aux->data!=elem){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){

    }
    else{
        return pos->data;
    }
}


template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=nullptr){
            std::cout<<aux->data<<std::endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}


int main() {
    LDLLSE<Socio> milista;
    Socio s,a;
    int op, aux;
    std::string auxs;

    do {
        std::cout<<std::endl<<std::endl;
        std::cout<<"Ingrese una opcion: "<<std::endl;
        std::cout<<"1. Registrar nuevo socio "<<std::endl;
        std::cout<<"2. Dar de baja un socio "<<std::endl;
        std::cout<<"3. Generar un reporte "<<std::endl;
        std::cout<<"4. Buscar socio por nombre y domicilio "<<std::endl;
        std::cout<<"5. Salir "<<std::endl;
        std::cin>>op;


        switch(op) {
            case 1:
                std::cin>>s;
                if(milista.localiza(s) == nullptr) {
                    milista.inserta(milista.primero(),s);
                    }
                else {
                    std::cout<<std::endl<<"Numero de Socio Invalido"<<std::endl;
                    }
                break;
            case 2:
                std::cout<<"Ingrese el numero de socio: "<<std::endl;
                std::cin>>aux;
                s.setNumeroSocio(aux);
                if(milista.elimina(milista.localiza(s))) {
                    std::cout<<"Eliminado con exito"<<std::endl;
                    }
                else {
                    std::cout<<"error al eliminar\n"<<std::endl;
                    }
                break;
            case 3:
//                std::cout<<milista.toString();
//                std::cout<<std::endl;

                std::cout<<"Numero\tNombre\tDomicilio\t\tAnio\n\n";
                milista.imprime();
                std::cout<<std::endl;
                break;
            case 4:
                std::cout<<"Ingrese el nombre del socio: "<<std::endl;
                std::cin>>auxs;
                a.setNombreSocio(auxs);
                std::cout<<"Ingrese el domicilio del socio: "<<std::endl;
                std::cin>>auxs;
                a.setDomicilio(auxs);
                std::cout<<"Numero\tNombre\tDomicilio\t\tAnio\n\n";
                std::cout<<milista.recupera(milista.localiza(a)).toString();

                break;
            case 5:
                break;
            }
        }while(op!=5);
    return 0;
    }
