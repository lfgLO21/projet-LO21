#include "operation.h"

Operation::Operation()
{
}

Constante* Addition::application(const Constante& c1, const Constante& c2){

        Constante* result;

        if(c1.getType()==4 || c2.getType()==4)
        {
            result = c1+c2;
            return result;
        }
        else if(c1.getType() > c2.getType()){
                result = c1+c2;
        }
        else{
                result = c2+c1;
        }
        return result;
}

Constante* Soustraction::application(const Constante& c1, const Constante& c2){

       Constante* result;
       if(c1.getType()==4 || c2.getType()==4)
       {
           result = c1-c2;
           return result;
       }
       else if(c1.getType() > c2.getType()){
           result = c1-c2;
       }
       else{
           result = c2-c1;
       }
       return result;
}

Constante* Multiplication::application(const Constante& c1, const Constante& c2){

       Constante* result;
       if(c1.getType()==4 || c2.getType()==4)
       {
           result = c1*c2;
           return result;
       }
       else if(c1.getType() > c2.getType()){
           result = c1*c2;
       }
       else{
           result = c2*c1;
       }
       return result;
}

Constante* Division::application(const Constante& c1, const Constante& c2){

       Constante* result;
       if(c1.getType()==4 || c2.getType()==4)
       {
           result = c1/c2;
           return result;
       }
       else if(c1.getType() >= c2.getType()){
           result = c1/c2;
       }
       else{
           result = c2/c1;
       }
       return result;

}

bool Egal::application(const Constante& c1, const Constante& c2){

    bool result;
    if(c1.getType() > c2.getType()){
            result = c1==c2;
    }
    else{
            result = c2==c1;
    }
    return result;
}

bool Inferieur::application(const Constante& c1, const Constante& c2){

    bool result;
    if(c1.getType() > c2.getType()){
            result = c1<c2;
    }
    else{
            result = c2<c1;
    }
    return result;
}

Constante* POW::application(const Constante& c1, const Constante& c2){

       Constante* result = new Entier(1);
       if(c2.getType() != Constante::ENTIER)
           ;//erreur
       for(int i=0;i<static_cast<const Entier&>(c2).getEntier();i++)
            result = (*result) *c1;
       return result;

}

Constante* SIGN::application(const Constante& c1){
       return -c1;
}

Constante* SQUARE::application(const Constante& c1){
       return c1*c1;
}

Constante* CUBE::application(const Constante& c1){
       return POW::application(c1,Entier(3));
}

Constante* INV::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Rationnel(1,static_cast<const Entier&>(c1).getEntier());
                break;
                case Constante::RATIONNEL:
        result = Rationnel(1) / c1;
                break;
                case Constante::REEL:
        result = new Rationnel(1,(int)static_cast<const Reel&>(c1).getReel());
                break;
        }
       return result;
}

Constante* SQRT::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(sqrt(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(sqrt(static_cast<const Rationnel&>(c1).getNumerateur())/sqrt(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(sqrt(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* SIN::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(sin(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(sin(static_cast<const Rationnel&>(c1).getNumerateur())/sin(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(sin(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* SINH::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(sinh(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(sinh(static_cast<const Rationnel&>(c1).getNumerateur())/sinh(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(sinh(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* COS::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(cos(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(cos(static_cast<const Rationnel&>(c1).getNumerateur())/cos(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(cos(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* COSH::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(cosh(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(cosh(static_cast<const Rationnel&>(c1).getNumerateur())/cosh(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(cosh(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* TAN::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(tan(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(tan(static_cast<const Rationnel&>(c1).getNumerateur())/tan(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(tan(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* TANH::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(tanh(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(tanh(static_cast<const Rationnel&>(c1).getNumerateur())/tanh(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(tanh(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* LOG::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(log10(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(log10(static_cast<const Rationnel&>(c1).getNumerateur())/log10(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(log10(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}

Constante* LN::application(const Constante& c1){
       Constante* result;
        switch(c1.getType()){
                case Constante::ENTIER:
        result = new Reel(log(static_cast<const Entier&>(c1).getEntier()));
                break;
                case Constante::RATIONNEL:
        result = new Reel(log(static_cast<const Rationnel&>(c1).getNumerateur())/log(static_cast<const Rationnel&>(c1).getDenominateur()));
                break;
                case Constante::REEL:
        result = new Reel(log(static_cast<const Reel&>(c1).getReel()));
                break;
        }
       return result;
}
