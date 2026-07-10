//
// Created by Wstep on 7/10/2026.
//

#ifndef PROJECT1_UIFACE_H
#define PROJECT1_UIFACE_H


class UIface {
    private:

    public:
    bool running;
    void runMenu();

    //Load
    void load();

    void addPro();
    void sID();
    void updatePro();
    void removePro();
    void topX();
    void saveToFile();
    void exitOP();
};


#endif //PROJECT1_UIFACE_H