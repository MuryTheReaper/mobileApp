#include "gui.h"
#include <QApplication>

void runGUI(int argc, char **argv) {
  QApplication app(argc, argv);
  repository repo;
  validator val;
  services serv{repo, val};
  guiMain ui{serv};
  ui.show();
  app.exec();
}

int main(int argc, char **argv) {

  runGUI(argc, argv);

  //
  return 0;
}
