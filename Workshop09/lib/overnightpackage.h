//
// Created by Saeed Samimi on 5/22/2024.
//

#ifndef POSTSERVICE_OVERNIGHTPACKAGE_H
#define POSTSERVICE_OVERNIGHTPACKAGE_H

#include "package.h"

class OverNightPackage : public Package {
private:
  double m_fixed_price;

public:
  OverNightPackage(string name,
                   string lastName,
                   string address,
                   string city,
                   string united,
                   string sender_post,
                   string receiverPost,
                   int weight, double fixedPrice);
  [[nodiscard]] double getFixedPrice();
  void setFixedPrice(double new_fixed_price);
  double calculateCost() const override;
  
};


#endif //POSTSERVICE_OVERNIGHTPACKAGE_H
