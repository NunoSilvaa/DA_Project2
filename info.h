//
// Created by nmls1 on 22/05/2022.
//

#ifndef PROJETODA_2_INFO_H
#define PROJETODA_2_INFO_H


class info {
    int origin;
    int destiny;
    int capacity;
    int duration;
public:
    info();

    int getOrigin();
    int getDestiny();
    int getCapacity();
    int getDuration();

    void setOrigin(int origin);
    void setDestiny(int destiny);
    void setCapacity(int capacity);
    void setDuration(int duration);

};


#endif //PROJETODA_2_INFO_H
