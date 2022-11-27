#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Planta {
private:
    std::string specie;
    int an_plantare;
public:
    Planta() = default;

    Planta(const std::string &specie_, int an_plantare_);

    Planta(const Planta &planta);

    friend std::ostream & operator <<(std::ostream &out, Planta &planta);

    Planta& operator = (const Planta &planta){
        specie = planta.specie;
        an_plantare = planta.an_plantare;
        return *this;
    }

    ~Planta() = default;
};

Planta::Planta(const std::string &specie_, int an_plantare_) {
    this->specie = specie_;
    this->an_plantare = an_plantare_;
}

Planta::Planta(const Planta &planta) {
    this->specie = planta.specie;
    this->an_plantare = planta.an_plantare;
}

std::ostream & operator <<(std::ostream &out, Planta &planta){
    out << "Specie planta: " << planta.specie << ", plantata in anul: " << planta.an_plantare << "\n";
    return out;
}

class Vegetatie {
private:
    std::vector<Planta> plante;
    std::string tip; //copac, tufis, floare
public:
    Vegetatie() = default;

    Vegetatie(const std::vector <Planta> &plante_, const std::string &tip_);

    Vegetatie(const Vegetatie &vegetatie);

    Vegetatie& operator= (const Vegetatie &vegetatie){
        plante = vegetatie.plante;
        tip = vegetatie.tip;
        return *this;
    }

    friend std::ostream & operator <<(std::ostream &out, Vegetatie &vegetatie);

    void adugare_planta(Planta planta){
        plante.emplace_back(planta);
    }

    ~Vegetatie() = default;
};

Vegetatie::Vegetatie(const std::vector<Planta> &plante_, const std::string &tip_) {
    this->plante = plante_;
    this->tip = tip_;
}

Vegetatie::Vegetatie(const Vegetatie &vegetatie){
    this->plante = vegetatie.plante;
    this->tip = vegetatie.tip;
}

std::ostream & operator <<(std::ostream &out, Vegetatie &vegetatie){
    out << "Tip: " << vegetatie.tip << "\n";
    for(auto& planta : vegetatie.plante){
        out << planta;
    }
}

class Lac {
private:
    float suprafata;
    std::string tip; //natural, artificial
public:

    Lac() = default;

    Lac(float suprafata_, const std::string &tip_);

    Lac(const Lac &lac);

    Lac& operator=(const Lac &lac) {
        suprafata = lac.suprafata;
        tip = lac.tip;
        return *this;
    }

    float getSuprafata() const {
        return this->suprafata;
    }

    ~Lac() = default;

    friend std::ostream & operator <<(std::ostream &out, Lac &lac);
};

Lac::Lac(float suprafata_, const std::string &tip_) {
    this->suprafata = suprafata_;
    this->tip = tip_;
}

Lac::Lac(const Lac &lac) {
    this->suprafata = lac.suprafata;
    this->tip = lac.tip;
}

std::ostream & operator <<(std::ostream &out, Lac &lac) {
    out << "Tip lac: " << lac.tip << ", avand suprafata de: " << lac.suprafata << " m patrati\n";
    return out;
}

class Banci {
private:
    int numar;
    std::string culoare;
public:

    Banci() = default;

    Banci(int numar_, const std::string &culoare_);

    Banci(const Banci &banci);

    Banci& operator=(const Banci &banci) {
        numar = banci.numar;
        culoare = banci.culoare;
        return *this;
    }

    void afisbnc(){
        std::cout << culoare << " " << numar << "\n";
    }

    static Banci* sumaB(const std::vector<Banci> &banci) {
        int suma=0;
        for(int i = 0; i < banci.size(); i++)
            suma = suma + banci[i].numar;
        Banci* total = new Banci(suma, "Totalitatea bancilor");
        return total;
    }

    ~Banci() = default;

    friend std::ostream & operator <<(std::ostream &out, Banci &banci);
};

Banci::Banci(int numar_, const std::string &culoare_) {
    this->numar = numar_;
    this->culoare = culoare_;
}

Banci::Banci(const Banci &banci) {
    this->numar = banci.numar;
    this->culoare = banci.culoare;
}

std::ostream & operator <<(std::ostream &out, Banci &banci) {
    out << "Culoare banci: " << banci.culoare << ", numarul de bucati: " << banci.numar << "\n";
    return out;
}

class Parc {
private:
    std::string nume;
    float suprafata;
    Vegetatie vegetatie;
    std::vector<Banci> banci;
    Lac lac;
public:
    Parc(const std::string &nume_, float suprafata_, const Vegetatie vegetatie_, const std::vector<Banci> &banci_, const Lac &lac_);

    Parc(const Parc &parc);

    Parc& operator=(const Parc &parc) {
        nume = parc.nume;
        suprafata = parc.suprafata;
        vegetatie = parc.vegetatie;
        banci = parc.banci;
        lac = parc.lac;
        return *this;
    }

    friend Parc dimensiune(const Parc &parc) {
        if(parc.suprafata>parc.lac.getSuprafata())
            std::cout << "Suprafata parcului este mai mare decat cea a lacului\n";
        else std::cout << "Suprafata lacului este mai mare decat cea a parcului\n";
    }

    ~Parc() = default;

    friend std::ostream & operator <<(std::ostream &out, Parc &parc);

};

Parc::Parc(const std::string &nume_, float suprafata_, const Vegetatie vegetatie_, const std::vector<Banci> &banci_, const Lac &lac_) {
    this->nume = nume_;
    this->suprafata = suprafata_;
    this->vegetatie = vegetatie_;
    this->banci = banci_;
    this->lac = lac_;
}

Parc::Parc(const Parc &parc) {
    this->nume = parc.nume;
    this->suprafata = parc.suprafata;
    this->vegetatie = parc.vegetatie;
    this->lac = parc.lac;
    this->banci = parc.banci;
}

std::ostream & operator <<(std::ostream &out, Parc &parc) {
    out << "Date parc: \n";
    out << "Numele parcului: " << parc.nume << ", avand suprafata de: " << parc.suprafata << " m patrati\n";
    std::string input;
    int cont = 1;
    int info;
    std::string veg = "Vegetatie";
    std::string lac = "Lac";
    std::string bnc = "Banci";
    std::string da = "DA";
    std::string nu = "NU";

    while(cont!=0){
        out << "Selectati o categorie de informatii:\n";
        out << "Vegetatie / Lac / Banci\n";
        std::cin >> input;

        if(input.compare(veg) == 0)
            info=1;
        if(input.compare(lac)==0)
            info=2;
        if(input.compare(bnc)==0)
            info=3;

        switch (info) {
            case 1:
                out << "Vegetatia este formata din:\n";
                out << parc.vegetatie;
                break;
            case 2:
                out << "Lacul:\n";
                out << parc.lac;
                break;
            case 3:
                out << "Bancile:\n";
                for (int i = 0; i < parc.banci.size(); i++)
                    out << parc.banci[i];
                break;
        }
        out << "Doriti sa mai aflati informatii? DA/NU\n";
        std::cin >> input;
        if(input.compare(da)==0)
            cont = 1;
        if(input.compare(nu)==0)
            cont = 0;
    }
    return out;
}

int main(){
    Planta planta1, planta2, planta3, planta4, planta5;
    planta1 = {"Tei", 1950};
    planta2 = {"Trandafir", 2005};
    planta3 = {"Stejar", 1989};
    planta4 = {"Salcam", 1999};
    planta5 = {"Tuia", 2009};

    Vegetatie copaci({planta1}, "Copaci");
    copaci.adugare_planta(planta3);
    copaci.adugare_planta(planta4);

    Vegetatie flori({planta2}, "Flori"), tufe({planta5}, "Tufe");

//    std::cout << copaci;
//    std::cout << flori;
//    std::cout << tufe;
//    std::cout << "\n";

    Lac lac(123, "Natural");
//    std::cout << lac;
//    std::cout << "\n";

    std::vector<Banci> banci;
    banci.reserve(100);
    banci.emplace_back(12, "Rosii");
    banci.emplace_back(10, "Maro");
    banci.emplace_back(9, "Verzi");
    banci.emplace_back(15, "Albastre");

    Parc parc("IOR", 234, copaci, banci, lac);
    std::cout << parc;

//    Copaci* sumC = Copaci::sumaC(copaci);
//    sumC->afiscop();
//    delete sumC;

    std::cout << "\n";
    Banci* sumB = Banci::sumaB(banci);
//    sumB->afisbnc();
    delete sumB;

    //Parc dim = dimensiune(parc);
    return 0;
}