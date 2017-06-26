/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/ArrayList.h"
#include "../inc/Employee.h"



int main(void)
{
        startTesting(1);
        startTesting(2);
        startTesting(3);
        startTesting(4);

        startTesting(5);//al get

        startTesting(6);
        startTesting(7);
        startTesting(8);//al remove
        startTesting(9);//al clear
        //startTesting(10);//al clone

        startTesting(11);//al push
        startTesting(12);//index of
        startTesting(13);//al is empty
        startTesting(14);//al pop
        //startTesting(15);//al sublist
        startTesting(16);//al contains all
        startTesting(17);//al sort

    return 0;
}





