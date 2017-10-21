#include "robotcontroller.h"

robotController::robotController()
{

}

void robotController::loadConfiguration(const std::string &fileName)
{
    std::string message;
    if( fXMLReader.loadFile(fileName) ){
        message = fileName + " loaded!";
        ofLogNotice() << message;
    }else{
        message = "unable to load " + fileName + " - check data/ folder";
        ofLogError() << message;
    }

    // find port name and baudrate
    std::string portName = fXMLReader.getValue("port::name", "");
    int rate = fXMLReader.getValue("port::rate", 0);

    if (portName == "" || rate == 0)
    {
        ofLogError() << "name of the port and baud rate not find in xml";
    }
    else
    {
        fPortName = portName ;
        fRate = rate;
    }

    // find servos names
    fServosNames.clear();
    fServosIds.clear();
    fServosInitialPositions.clear();

    int nbServos = fXMLReader.getNumTags("servo");
    if (nbServos>0)
    {
        for(int i = 0; i < nbServos; i++)
        {
              fXMLReader.pushTag("servo", i);
              std::string servoName = fXMLReader.getValue("name","");
              int id = fXMLReader.getValue("id",0);
              int pinNb = fXMLReader.getValue("pinNb",0);
              int pos = fXMLReader.getValue("initialPos",0);
              ofLogNotice () << "Servo " << servoName << " id : " <<  id << " attached to pin " << pinNb;

              if (servoName!="" && pinNb!=0)
              {
                  fServosNames.push_back(servoName);
                  fServosIds.push_back(id);
                  fServosInitialPositions.push_back(pos);
              }
              fXMLReader.popTag();
         }

    }
}
