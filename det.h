#ifndef GUARD_det_h
#define GUARD_det_h

#include <string>
#include "TVector3.h"

// Holds basic properties of different Det parts
struct DetProp
{
    std::string name; // Identifies the type, short mnemonic style
    std::string description; // Longer description, for nice reporting
    double w, l; // dimensions of module in cm
    double alpha, beta; // tilt angles, usually 0. alpha around w, beta around l
    double pxW, pxL; // dimensions of pixel in mm
    double thickness; // thickness in mm
    double X0; // radiation length in g/cm2
    double NIL; // nuclear interaction length in g/cm2
    double density; // density in g/cm3
    int col; // color to be used to draw object
    double area() const { return w*l; };
    double xOverX0() const { return thickness*density/X0*0.1; }; // 0.1 cm/mm
    double xOverNIL() const { return thickness*density/NIL*0.1; }; // 0.1 cm/mm
};

class Det
{
    public:
        Det();
        void setDisk(double z, double r_min, double r_max, bool isVfpix, DetProp prop, std::string name = "");
        void setLayer(double r, double z_min, double z_max, bool isVfpix, DetProp prop, std::string name = "");
        bool hit(double eta, double &r, double &z, double &dX0, double &dNIL) const;
        double getEtaMin() const { return _eta_min; };
        double getEtaMax() const { return _eta_max; };
        bool getIsVfpix() const { return _isVfpix; };
        bool getIsDisk() const { return _isDisk; };
        int getNModules() const { return _nModules; };
        double getR0() const { return _vec_min.x(); };
        double getR1() const { return _vec_max.x(); };
        double getZ0() const { return _vec_min.z(); };
        double getZ1() const { return _vec_max.z(); };
        std::string getName() const { return _name; };
        int getColor() const { return _properties.col; };
        ClassDef(Det, 1);

    private:
        void calcEtaBoundaries(); // calculates the eta coverage of the given detector unit

        std::string _type;
        TVector3 _vec_min, _vec_max; // min/max ordered by eta
        double _eta_min, _eta_max;
        bool _isVfpix;
        bool _isDisk;
        int _nModules;
        std::string _name;
        DetProp _properties;
        double _fillfactor;
};

#endif
