/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include <bcm/nat.h>
#include <bcm_int/control.h>

#include <bcm_int/ltsw/xgs/nat.h>
#include <bcm_int/ltsw/nat.h>
#include <bcm_int/ltsw/lt_intf.h>
#include <bcm_int/ltsw/dev.h>

#include <shr/shr_debug.h>
#include <bcmltd/chip/bcmltd_str.h>

/******************************************************************************
 * Local definitions
 */

#define BSL_LOG_MODULE BSL_LS_BCM_L3

/******************************************************************************
 * Private functions
 */

/******************************************************************************
 * Public functions
 */

int
xgs_ltsw_nat_init(int unit)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_detach(int unit)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_pub_info_get(
    int unit,
    bcmint_nat_pub_info_t *nat_pub)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_egress_add(
    int unit,
    bcm_l3_nat_egress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_egress_destroy(
    int unit,
    bcm_l3_nat_egress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_egress_get(
    int unit,
    bcm_l3_nat_egress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_egress_traverse(
    int unit,
    uint32_t flags,
    bcm_l3_nat_egress_traverse_cb cb,
    void *user_data)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_ingress_add(
    int unit,
    bcm_l3_nat_ingress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_ingress_delete(
    int unit,
    bcm_l3_nat_ingress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_ingress_find(
    int unit,
    bcm_l3_nat_ingress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_ingress_delete_all(
    int unit,
    bcm_l3_nat_ingress_t *nat_info)
{
    return SHR_E_UNAVAIL;
}

int
xgs_ltsw_nat_ingress_traverse(
    int unit,
    uint32_t flags,
    bcm_l3_nat_ingress_traverse_cb cb,
    void *user_data)
{
    return SHR_E_UNAVAIL;
}
