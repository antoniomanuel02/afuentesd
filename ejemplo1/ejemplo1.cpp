#include "ejemplo1.h"

ejemplo1::ejemplo1(): Ui_Counter()
{
	setupUi(this);
	show();
	connect(button, SIGNAL(clicked()), this, SLOT(doButton()) );//connect manda estimulos 
	connect(&contador, SIGNAL(timeout()), this, SLOT(doStimulos()) );//timeout ya esta definida en qTimer. timeout manda estimulos todo el rato
	connect(horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(frecuencia()) );
	
	contador.start(1000);
	

}

ejemplo1::~ejemplo1()
{}

void ejemplo1::doButton()
{
  qDebug() << "click on button";
   
  if(contador.isActive()) {
    qDebug() << "Parando contador";
    contador.stop();  
  }else {
    int valor;
    valor = horizontalSlider->value();
    contador.start(valor);
    qDebug() << "reanudando contador";
  }
	
}

void ejemplo1::doStimulos() {
  
  qDebug() << "Señal recibida";  
  lcdNumber->display(lcdNumber->intValue()+ 1);
  
}

void ejemplo1::frecuencia()
{
  int valor;
  if(contador.isActive()){
    
    valor = horizontalSlider->value();
    contador.start(valor);
    
  }
}








