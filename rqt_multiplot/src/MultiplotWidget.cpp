/******************************************************************************
 * Copyright (C) 2015 by Ralf Kaestner                                        *
 * ralf.kaestner@gmail.com                                                    *
 *                                                                            *
 * This program is free software; you can redistribute it and/or modify       *
 * it under the terms of the Lesser GNU General Public License as published by*
 * the Free Software Foundation; either version 3 of the License, or          *
 * (at your option) any later version.                                        *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the               *
 * Lesser GNU General Public License for more details.                        *
 *                                                                            *
 * You should have received a copy of the Lesser GNU General Public License   *
 * along with this program. If not, see <http://www.gnu.org/licenses/>.       *
 ******************************************************************************/

#include <ros/package.h>

#include <ui_MultiplotWidget.h>

#include "rqt_multiplot/MultiplotWidget.h"

namespace rqt_multiplot {

/*****************************************************************************/
/* Constructors and Destructor                                               */
/*****************************************************************************/

MultiplotWidget::MultiplotWidget(QWidget* parent) :
  QWidget(parent),
  ui_(new Ui::MultiplotWidget()),
  config_(new MultiplotConfig(this)) {
  ui_->setupUi(this);
  
  ui_->configWidget->setConfig(config_);
  ui_->plotTableConfigWidget->setConfig(config_->getTableConfig());
  ui_->plotTableWidget->setConfig(config_->getTableConfig());
}

MultiplotWidget::~MultiplotWidget() {
}

/*****************************************************************************/
/* Accessors                                                                 */
/*****************************************************************************/

MultiplotConfig* MultiplotWidget::getConfig() const {
  return config_;
}

}
