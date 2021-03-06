#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cmath>
#include <map>
#include <cassert>
using namespace std;

namespace Utils 
{
    int stringToInt(string value);
    string intToString(int value);

    // returns the closest value for key 
    template<class K, class V>
    V closest(map<K, V> & _map, const K & key) {
        assert(_map.size() > 0);
        if (_map.size() == 1)
            return _map.begin()->second;

        typename map<K, V>::const_iterator it = _map.lower_bound(key);
        typename map<K, V>::const_iterator prev = it; prev--;
        if (it == _map.end() || (abs(prev->first - key) < abs(it->first - key)))
            return prev->second;
        else
            return it->second;
    }

    template<class K, class V>
    V value(const map<K, V> & _map, const K & key, const V & default_value) {
        typename map<K, V>::const_iterator it = _map.find(key);
        if (it == _map.end())
            return default_value;
        
        return it->second;
    }
};

#endif
