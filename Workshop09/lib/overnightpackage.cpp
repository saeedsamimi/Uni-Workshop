//
// Created by Saeed Samimi on 5/22/2024.
//

#include "overnightpackage.h"

#define MV(x) std::move(x)

OverNightPackage::OverNightPackage(string name,
                                   string lastName,
                                   string address,
                                   string city,
                                   string united,
                                   string sender_post,
                                   string receiver_post,
                                   int weight, double fixed_price) :
        Package(MV(name),
                MV(lastName),
                MV(address),
                MV(city),
                MV(united),
                MV(sender_post),
                MV(receiver_post), weight),
        m_fixed_price(std::max(0.0, fixed_price)) {}

double OverNightPackage::getFixedPrice() {
  return m_fixed_price;
}

void OverNightPackage::setFixedPrice(double new_fixed_price) {
  m_fixed_price = new_fixed_price;
}

double OverNightPackage::calculateCost() const{
  return Package::calculateCost() + m_fixed_price;
}

#undef MV
