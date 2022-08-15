#ifndef GUI_H
#define GUI_H

#include "services.h"
#include <QTabWidget>
#include <QWidget>

class guiMain : public QTabWidget {
private:
  services &serv;

  void initGUI();
  void connect_signals();

public:
  guiMain(services &serv) : serv{serv} {
    initGUI();
    connect_signals();
  }
};

#endif // GUI_H
