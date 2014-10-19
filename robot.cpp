/*
 * GESTION ROBOT OLINUXINO.
 * Debut 15/10/2014
 */

#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WText>

#include <Wt/WGridLayout>
#include <Wt/WVBoxLayout>


// c++0x only, for std::bind
// #include <functional>

using namespace Wt;

class RobotApplication : public WApplication
{
public:
  RobotApplication(const WEnvironment& env);

private:
  WContainerWidget *containeur;
  WText *boutonActive;
    

  void avancer();//methodes
  void reculer();
  void gauche();
  void droite();
  void stop();
};

/*
 * constructeur de notre classe RobotApplication
*/
RobotApplication::RobotApplication(const WEnvironment& env)
  : WApplication(env)
{
  setTitle("Gestion de robot avec Wt!!");                  // application title

  containeur = new WContainerWidget(root()); //le conteneur sur la feuille
  containeur->resize(400, 400);
  containeur->setStyleClass("yellow-box centered");

  boutonActive = new WText("");

  Wt::WVBoxLayout *vbox = new Wt::WVBoxLayout();
  containeur->setStyleClass("yellow-box");
  containeur->setLayout(vbox);
  
  Wt::WGridLayout *grilleAffichageBouton = new WGridLayout();

  WPushButton *buttonAvancer = new WPushButton("AVANCER");              // on cree un bouton
  buttonAvancer->setMargin(5, Left);                            // marge de 5 pixels

  WPushButton *buttonReculer = new WPushButton("RECULER");              // on cree un bouton
  buttonReculer->setMargin(5, Left);                            // marge de 5 pixels

  WPushButton *buttonGauche = new WPushButton("GAUCHE");              // on cree un bouton
  buttonGauche->setMargin(5, Left);                            // marge de 5 pixels

  WPushButton *buttonDroite = new WPushButton("DROITE");              // on cree un bouton
  buttonDroite->setMargin(5, Left);                            // marge de 5 pixels

  WPushButton *buttonStop = new WPushButton("STOP");              // on cree un bouton
  buttonStop->setMargin(5, Left);                           // marge de 5 pixels
  //buttonDroite->setIcon(Wt::WLink("Fleche_droite_bleue.png"));//cela déforme les boutons

  vbox->addWidget(new WText("GESTION DU ROBOT - CARTE OLINUXINO"));
  vbox->addLayout(grilleAffichageBouton);
  vbox->addWidget(boutonActive);  
	
  grilleAffichageBouton->addWidget(buttonAvancer,0,1);
  grilleAffichageBouton->addWidget(buttonReculer,2,1); 
  grilleAffichageBouton->addWidget(buttonGauche,1,0);
  grilleAffichageBouton->addWidget(buttonDroite,1,2);
  grilleAffichageBouton->addWidget(buttonStop,1,1);
 
  /*
   * on connecte les signaux sur slots
   */
  buttonAvancer->clicked().connect(this, &RobotApplication::avancer);
  buttonReculer->clicked().connect(this, &RobotApplication::reculer);
  buttonGauche->clicked().connect(this, &RobotApplication::gauche);
  buttonDroite->clicked().connect(this, &RobotApplication::droite);
  buttonStop->clicked().connect(this, &RobotApplication::stop);
  
}

void RobotApplication::avancer()
{
  
 	
   boutonActive->setText(Wt::WString::fromUTF8("Bouton Avancer activé"));
  
}

void RobotApplication::reculer()
{
  
 	
   boutonActive->setText(Wt::WString::fromUTF8("Bouton Reculer activé"));
  
}

void RobotApplication::gauche()
{
  
 	
   boutonActive->setText(Wt::WString::fromUTF8("Bouton Gauche activé"));
  
}

void RobotApplication::droite()
{
  
 	
   boutonActive->setText(Wt::WString::fromUTF8("Bouton Droite activé"));
  
}

void RobotApplication::stop()
{
  
 	
   boutonActive->setText(Wt::WString::fromUTF8("Bouton Stop activé"));
  
}

WApplication *createApplication(const WEnvironment& env)
{
  /*
   * You could read information from the environment to decide whether
   * the user has permission to start a new application
   */
  return new RobotApplication(env);
}

int main(int argc, char **argv)
{
  /*
   * Your main method may set up some shared resources, but should then
   * start the server application (FastCGI or httpd) that starts listening
   * for requests, and handles all of the application life cycles.
   *
   * The last argument to WRun specifies the function that will instantiate
   * new application objects. That function is executed when a new user surfs
   * to the Wt application, and after the library has negotiated browser
   * support. The function should return a newly instantiated application
   * object.
   */
  return WRun(argc, argv, &createApplication);
}

