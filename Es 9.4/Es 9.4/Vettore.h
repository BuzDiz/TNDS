#ifndef __Vettore_h__
#define __Vettore_h__

class Vettore
{
public:
  Vettore();
  Vettore(unsigned int );
  Vettore(const Vettore &);

  Vettore& operator=(const Vettore&);
  ~Vettore();

  int getIndex() const;
  void setIndex(unsigned int n) { index = n; }
  void addValue(double );
  double getValue(unsigned int ) const;
  void scambia(unsigned int, unsigned int ) const;
  void setValue(unsigned int, double );
protected:
  double *value;
  unsigned int index;

};

#endif
