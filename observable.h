/*
 *    NUtils, a collection of utilities for numerical computation
 *    Copyright (C) 2013  Miha Čančula <miha@noughmad.eu>
 * 
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 * 
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 * 
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include <cmath>

template<class T, class V, class S = V> class Observable
{
public:
    Observable();
    ~Observable();
    
    void insertValue(T time, const V& value);
    
    V average();
    S variance();
    int samples();
    
private:
    V mAverage;
    S mSquareAverage;
    int mSamples;
};

template<class T, class V, class S>
Observable<T, V, S>::Observable()
: mSamples(0)
, mAverage(0)
, mSquareAverage(0)
{

}

template<class T, class V, class S>
Observable<T, V, S>::~Observable()
{

}

template<class T, class V, class S>
void Observable<T, V, S>::insertValue(T time, const V& value)
{
    ++mSamples;
    const double f = 1.0 / mSamples;

    mAverage = f * value + (1-f) * mAverage;
    mSquareAverage = f * (value * value) + (1-f) * mSquareAverage;
}

template<class T, class V, class S>
V Observable<T, V, S>::average()
{
    return mAverage;
}

template<class T, class V, class S>
S Observable<T, V, S>::variance()
{
    return sqrt(mSquareAverage - mAverage * mAverage);
}

template<class T, class V, class S>
int Observable<T, V, S>::samples()
{
    return mSamples;
}

#endif // OBSERVABLE_H
