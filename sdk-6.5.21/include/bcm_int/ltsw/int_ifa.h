/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef BCMI_LTSW_INT_IFA_H
#define BCMI_LTSW_INT_IFA_H

/*!
 * \brief Initialize the IFA module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE Success.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_int_ifa_init(int unit);

/*!
 * \brief De-initialize the IFA module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE Success.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_int_ifa_deinit(int unit);

#endif /* BCMI_LTSW_INT_IFA_H */