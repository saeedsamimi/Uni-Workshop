//
// Created by Saeed Samimi on 5/22/2024.
//

#ifndef POSTSERVICE_TWODAYPACKAGE_H
#define POSTSERVICE_TWODAYPACKAGE_H

#include "package.h"

class TwoDayPackage : public Package {
private:
  double m_fixed_price;

public:
  TwoDayPackage(string name,
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


#endif //POSTSERVICE_TWODAYPACKAGE_H
