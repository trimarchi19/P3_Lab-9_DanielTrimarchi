#ifndef ALDEANO_H
#define ALDEANO_H 
class Aldeano
{
private:
	char sexo;
	int costo_alimento;
public:
	Aldeano();
	Aldeano(char,int);
	~Aldeano();
	char getSexo();
	int getCosto();

	void setSexo(char);
	void setCosto(int);
};
#endif