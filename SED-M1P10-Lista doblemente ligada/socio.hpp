#ifndef SOCIO_INCLUDED
#define SOCIO_INCLUDED

class Socio{
    private:
        int NumeroSocio;
        std::string NombreSocio;
        std::string Domicilio;
        int AnioIngreso;

    public:
        Socio();
        Socio(const Socio&);

        int getNumeroSocio();
        std::string getNombreSocio();
        std::string getDomicilio();
        int getAnioIngreso();

        void setNumeroSocio(const int&);
        void setNombreSocio(const std::string&);
        void setDomicilio(const std::string&);
        void setAnioIngreso(const int&);

        std::string toString() const;

        Socio& operator =(const Socio&);
        bool operator ==(const Socio&);
        bool operator !=(const Socio&);
        bool operator <(const Socio&);
        bool operator <=(const Socio&);
        bool operator >(const Socio&);
        bool operator >=(const Socio&);

        friend std::istream & operator>>(std::istream &O, Socio &x);
        friend  std::ostream & operator<<(std::ostream &O, Socio &x);
};
#endif // SOCIO_INCLUDED

///IMPLEMENTACION
    Socio::Socio():NumeroSocio(NULL),NombreSocio(""),Domicilio(""),AnioIngreso(0) {

        }

    Socio::Socio(const Socio& s) {
        NumeroSocio = s.NumeroSocio;
        NombreSocio = s.NombreSocio;
        Domicilio = s.Domicilio;
        AnioIngreso = s.AnioIngreso;
        }

    int Socio::getNumeroSocio() {
        return NumeroSocio;
        }

    std::string Socio::getNombreSocio() {
        return NombreSocio;
        }

    std::string Socio::getDomicilio() {
        return Domicilio;
        }

    int Socio::getAnioIngreso() {
        return AnioIngreso;
        }

    void Socio::setNumeroSocio(const int& ns) {
        NumeroSocio = ns;
        }

    void Socio::setNombreSocio(const std::string& ns) {
        NombreSocio = ns;
        }

    void Socio::setDomicilio(const std::string& d) {
        Domicilio = d;
        }

    void Socio::setAnioIngreso(const int& ai) {
        AnioIngreso = ai;
        }

    std::string Socio::toString() const {
        return std::to_string(NumeroSocio) + "\t" + NombreSocio + "\t" + Domicilio + "\t" + std::to_string(AnioIngreso) + "\n";
        }


    Socio& Socio::operator=(const Socio& s) {
        NumeroSocio = s.NumeroSocio;
        NombreSocio = s.NombreSocio;
        Domicilio = s.Domicilio;
        AnioIngreso = s.AnioIngreso;
        return *this;
        }

    bool Socio::operator==(const Socio& s) {
        if(s.NumeroSocio!=NULL){
             return NumeroSocio == s.NumeroSocio;
        }else{
            return NombreSocio == s.NombreSocio && Domicilio == s.Domicilio;
        }
        }

     bool Socio::operator!=(const Socio& s) {
        if(s.NumeroSocio!=NULL){
             return NumeroSocio != s.NumeroSocio;
        }else{
            return NombreSocio != s.NombreSocio && Domicilio != s.Domicilio;
        }
        }

    bool Socio::operator<(const Socio& s) {
        return NumeroSocio < s.NumeroSocio;
        }

    bool Socio::operator<=(const Socio& s) {
        return NumeroSocio <= s.NumeroSocio;
        }

    bool Socio::operator>(const Socio& s) {
        return NumeroSocio > s.NumeroSocio;
        }

    bool Socio::operator>=(const Socio& s) {
        return NumeroSocio >= s.NumeroSocio;
        }

    std::istream & operator>>(std::istream &O, Socio &x) {
        std::string s;
        std::cout<<"\n Numero de Socio: ";
        O>>x.NumeroSocio;
        std::cout<<"\n Nombre de Socio: ";
        O>>x.NombreSocio;
        std::cout<<"\n Anio de Ingreso: ";
        O>>x.AnioIngreso;
        std::cout<<"\n Domicilio: ";
        O>>x.Domicilio;
        return O;
        }


    std::ostream & operator<<(std::ostream &O, Socio &x) {
        O<<x.NumeroSocio<<"\t";
        O<<x.NombreSocio<<"\t";
        O<<x.AnioIngreso<<"\t";
        O<<x.Domicilio<<"\t";
        return O;
        }



