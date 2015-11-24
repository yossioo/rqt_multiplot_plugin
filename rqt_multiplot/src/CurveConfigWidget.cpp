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

#include <ui_CurveConfigWidget.h>

#include "rqt_multiplot/CurveConfigWidget.h"

namespace rqt_multiplot {

/*****************************************************************************/
/* Constructors and Destructor                                               */
/*****************************************************************************/

CurveConfigWidget::CurveConfigWidget(QWidget* parent) :
  QWidget(parent),
  ui_(new Ui::CurveConfigWidget()),
  config_(new CurveConfig(this)),
  messageTopicRegistry_(new MessageTopicRegistry(this)),
  messageTypeRegistry_(new MessageTypeRegistry(this)) {
  ui_->setupUi(this);
  
  ui_->curveAxisConfigWidgetX->setConfig(config_->getAxisConfig(
    CurveConfig::X));
  ui_->curveAxisConfigWidgetY->setConfig(config_->getAxisConfig(
    CurveConfig::Y));
  ui_->curveColorWidget->setColor(config_->getColor());
  
  connect(config_, SIGNAL(titleChanged(const QString&)), this,
    SLOT(configTitleChanged(const QString&)));
  
  connect(ui_->lineEditTitle, SIGNAL(editingFinished()), this,
    SLOT(lineEditTitleEditingFinished()));
  
  messageTopicRegistry_->update();
  messageTypeRegistry_->update();
  
  configTitleChanged(config_->getTitle());
}

CurveConfigWidget::~CurveConfigWidget() {
  delete ui_;
}

/*****************************************************************************/
/* Accessors                                                                 */
/*****************************************************************************/

void CurveConfigWidget::setConfig(const CurveConfig& config) {
  *config_ = config;
}

CurveConfig& CurveConfigWidget::getConfig() {
  return *config_;
}

const CurveConfig& CurveConfigWidget::getConfig() const {
  return *config_;
}

/*****************************************************************************/
/* Slots                                                                     */
/*****************************************************************************/

void CurveConfigWidget::configTitleChanged(const QString& title) {
  ui_->lineEditTitle->setText(title);
}

void CurveConfigWidget::lineEditTitleEditingFinished() {
  config_->setTitle(ui_->lineEditTitle->text());
}

}
