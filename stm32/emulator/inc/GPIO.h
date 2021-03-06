/*
 * Copyright (c) 2013-2014 ELL-i co-operative.
 *
 * This is part of ELL-i software.
 *
 * ELL-i software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ELL-i software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ELL-i software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Register.h>
#include <Register_GPIO_MODER.h>
//#include <Register_GPIO_OTYPER.h>
//#include <Register_GPIO_OSPEEDR.h>
#include <Register_GPIO_PUPDR.h>
#include <Register_GPIO_IDR.h>
#include <Register_GPIO_ODR.h>
#if defined(__STM32F407__) || defined(__STM32F334__)
# include <Register_GPIO_BSRRL.h>
  //#include <Register_GPIO_LCKR.h>
# include <Register_GPIO_AFR.h>
# include <Register_GPIO_BSRRH.h>
#elif defined(__STM32F051__)
# include <Register_GPIO_BSRR.h>
  //#include <Register_GPIO_LCKR.h>
# include <Register_GPIO_AFR.h>
# include <Register_GPIO_BRR.h>
#else
# error "Unknown MCU die.  Please define."
#endif

class GeneralPurposeInputOutput {
public:
    Register_GPIO_MODER MODER;
    //Register_GPIO_OTYPER OTYPER;
    //Register_GPIO_OSPEEDR OSPEEDR;
    Register_GPIO_PUPDR PUPDR;
    Register_GPIO_ODR ODR;
    Register_GPIO_IDR IDR;
#if defined(__STM32F407__) || defined(__STM32F334__)
    Register_GPIO_BSRRL BSRRL;
    Register_GPIO_AFR AFR[2];
    //Register_GPIO_LCKR LCKR;
    Register_GPIO_BSRRH BSRRH;
#elif defined(__STM32F051__)
    Register_GPIO_BSRR BSRR;
    Register_GPIO_AFR AFR[2];
    //Register_GPIO_LCKR LCKR;
    Register_GPIO_BRR BRR;
#else
# error "Unknown MCU die.  Please define."
#endif
protected:
    GeneralPurposeInputOutput()
        : ODR(IDR)
#if defined(__STM32F407__) || defined(__STM32F334__)
        , BSRRL(ODR)
        , BSRRH(ODR)
#elif defined(__STM32F051__)
        , BSRR(ODR)
        , BRR(ODR)
#else
# error "Unknown MCU die.  Please define."
#endif
        {}
public:
    static GeneralPurposeInputOutput GPIOA;
    static GeneralPurposeInputOutput GPIOB;
    static GeneralPurposeInputOutput GPIOC;
    static GeneralPurposeInputOutput GPIOD;
    static GeneralPurposeInputOutput GPIOE;
    static GeneralPurposeInputOutput GPIOF;
    static GeneralPurposeInputOutput GPIOG;
    static GeneralPurposeInputOutput GPIOH;
    static GeneralPurposeInputOutput GPIOI;
};

GeneralPurposeInputOutput *const GPIOA = &GeneralPurposeInputOutput::GPIOA;
GeneralPurposeInputOutput *const GPIOB = &GeneralPurposeInputOutput::GPIOB;
GeneralPurposeInputOutput *const GPIOC = &GeneralPurposeInputOutput::GPIOC;
GeneralPurposeInputOutput *const GPIOD = &GeneralPurposeInputOutput::GPIOD;
GeneralPurposeInputOutput *const GPIOE = &GeneralPurposeInputOutput::GPIOE;
GeneralPurposeInputOutput *const GPIOF = &GeneralPurposeInputOutput::GPIOF;
GeneralPurposeInputOutput *const GPIOG = &GeneralPurposeInputOutput::GPIOG;
GeneralPurposeInputOutput *const GPIOH = &GeneralPurposeInputOutput::GPIOH;
GeneralPurposeInputOutput *const GPIOI = &GeneralPurposeInputOutput::GPIOI;
