/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Finalpr.h
 * Author: 2876229
 *
 * Created on July 31, 2021, 8:06 PM
 */

#ifndef FINALPR_H
#define FINALPR_H

class Finalpr{
protected:
    int total;
    int prev;
public:
    void setTot(int t){
        total=t;
    }
    int getTot(){
        return total;
    }
    void preve(int p){
        prev = p;
    }
    int gprev(){
        return prev;
    }
};

#endif /* FINALPR_H */

