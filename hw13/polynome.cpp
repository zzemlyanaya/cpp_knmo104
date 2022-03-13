//
// Created by zzemlyanaya on 12.03.2022.
//

#include "polynome.h"


Polynome::Polynome() {
    deg = 0;
    coeff = new double[0];
}

Polynome::Polynome(int deg) {
    this->deg = deg;
    this->coeff = new double [deg+1];
    for (int i = 0; i <= deg; ++i) {
        this->coeff[i] = 0;
    }
}

Polynome::Polynome(int deg, double *coeff) {
    this->deg = deg;
    this->coeff = coeff;
}

Polynome::Polynome(Polynome* p) {
    this->deg = p->deg;
    this->coeff = new double [p->deg+1];
    for (int i = 0; i <= p->deg; ++i) {
        this->coeff[i] = p->coeff[i];
    }
}



ostream &operator<<(ostream &os, Polynome p) {
    if (p.isZero()) {
        os << "Zero polynome" << endl;
        return os;
    }

    for (int i = 0; i <= p.deg; i++) {
        if (p.coeff[i] != 0) {
            if (p.coeff[i] != 1 || i == 0) os << p.coeff[i];
            if (i != 0) os << "x";
            if (i > 1) os << "^" << i << " "; else os << " ";
        }
    }
    os << endl;
    return os;
}

istream &operator>>(istream &is, Polynome &p) {
    for (int i = 0; i <= p.deg; ++i) {
        is >> p.coeff[i];
    }
    return is;
}



Polynome Polynome::operator+(Polynome rgh) {
    if (this->isZero()) return rgh;
    if (rgh.isZero()) return *this;

    Polynome* mmax;
    Polynome* mmin;

    if (this->deg >= rgh.deg) {
        mmax = this;
        mmin = &rgh;
    } else {
        mmax = &rgh;
        mmin = this;
    }

    Polynome res = Polynome(mmax->deg);
    for (int i = 0; i <= mmax->deg; ++i) {
        res.coeff[i] = mmax->coeff[i];
        if (i <= mmin->deg) res.coeff[i] += mmin->coeff[i];
    }

    return res;
}

Polynome Polynome::operator-(Polynome rgh) {
    if (rgh.isZero()) return *this;

    for (int i = 0; i <= rgh.deg; ++i) {
        rgh.coeff[i] *= -1;
    }

    if (this->isZero()) {
        for (int i = 0; i <= rgh.deg; ++i) {
            rgh.coeff[i] *= -1;
        }

        return rgh;
    }

    Polynome* mmax;
    Polynome* mmin;

    if (this->deg >= rgh.deg) {
        mmax = this;
        mmin = &rgh;
    } else {
        mmax = &rgh;
        mmin = this;
    }

    Polynome res = Polynome(mmax->deg);
    for (int i = 0; i <= mmax->deg; ++i) {
        res.coeff[i] = mmax->coeff[i];
        if (i <= mmin->deg) res.coeff[i] += mmin->coeff[i];
    }

    if (res.coeff[res.deg] == 0) res.deg = 0;

    for (int i = 0; i <= rgh.deg; ++i) {
        rgh.coeff[i] *= -1;
    }

    return res;
}

Polynome Polynome::operator*(Polynome rgh) {
    if (this->isZero() || rgh.isZero()) return Polynome(0);

    Polynome res = Polynome(this->deg+rgh.deg);
    for (int i = 0; i <= this->deg; ++i) {
        for (int j = 0; j <= rgh.deg; ++j) {
            res.coeff[i+j] += this->coeff[i]*rgh.coeff[j];
        }
    }

    return res;
}

Polynome Polynome::operator/(double t) {
    Polynome res = Polynome(this);
    for (int i = 0; i <= this->deg; ++i) {
        res.coeff[i] /= t;
    }

    return res;
}

bool Polynome::isZero() {
    for (int i = 0; i < this->deg; i++){
        if (this->coeff[i] != 0) return false;
    }
    return true;
}

double Polynome::at(double x) {
    double res = 0;
    for (int i = 0; i <= this->deg; ++i) {
        res += pow(x, i) * this->coeff[i];
    }

    return res;
}

Polynome Polynome::derivative() {
    Polynome res = Polynome(this->deg-1);
    for (int i = 1; i <= this->deg; ++i) {
        res.coeff[i-1] = this->coeff[i];
        if (i > 1) res.coeff[i-1]*= i-1;
    }

    return res;
}