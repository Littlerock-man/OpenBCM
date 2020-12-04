/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include <bcm_int/ltsw/mbcm/tunnel.h>
#include <bcm_int/ltsw/xgs/tunnel.h>
#include "sub_dispatch.h"

#include <shr/shr_debug.h>

/******************************************************************************
 * Local definitions
 */

#define BSL_LOG_MODULE BSL_LS_BCM_TUNNEL

/******************************************************************************
 * Private functions
 */

static int
bcm56990_a0_ltsw_tunnel_init_lt_db(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_init_lt_db(unit));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_init(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_init(unit));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_free_resource(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_free_resource(unit));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_initiator_get(
    int unit,
    bcm_l3_intf_t *intf,
    bcm_gport_t tunnel_id,
    bcm_tunnel_initiator_t *tnl_info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_initiator_get(unit, intf, tunnel_id, tnl_info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_initiator_traverse(
    int unit,
    bcm_tunnel_initiator_traverse_cb cb,
    void *user_data)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_initiator_traverse(unit, cb, user_data));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_initiator_set(
    int unit,
    bcm_l3_intf_t *intf,
    bcm_tunnel_initiator_t *tnl_info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_initiator_set(unit, intf, tnl_info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_initiator_clear(
    int unit,
    bcm_l3_intf_t *intf)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_initiator_clear(unit, intf));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_initiator_flexctr_object_get(
    int unit,
    bcm_if_t intf,
    uint32_t *value)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_initiator_flexctr_object_get(unit, intf, value));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_add(
    int unit,
    bcm_tunnel_terminator_t *tnl_term_info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_add(unit, tnl_term_info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_get(
    int unit,
    bcm_tunnel_terminator_t *tnl_term_info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_get(unit, tnl_term_info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_delete(
    int unit,
    bcm_tunnel_terminator_t *tnl_term_info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_delete(unit, tnl_term_info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_traverse(
    int unit,
    bcm_tunnel_terminator_traverse_cb cb,
    void *user_data)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_traverse(unit, cb, user_data));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_stat_attach(
    int unit,
    bcm_tunnel_terminator_t *terminator,
    bcmi_ltsw_flexctr_counter_info_t *info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_stat_attach(unit, terminator, info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_stat_detach(
    int unit,
    bcm_tunnel_terminator_t *terminator)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_stat_detach(unit, terminator));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_flexctr_object_set(
    int unit,
    bcm_tunnel_terminator_t *terminator,
    uint32 value)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_flexctr_object_set(unit, terminator, value));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_flexctr_object_get(
    int unit,
    bcm_tunnel_terminator_t *terminator,
    uint32 *value)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_flexctr_object_get(unit, terminator, value));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_terminator_flexctr_info_get(
    int unit,
    bcm_tunnel_terminator_t *terminator,
    bcmi_ltsw_flexctr_counter_info_t *info)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_terminator_flexctr_info_get(unit, terminator, info));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_type_support_check(
    int unit,
    bcm_tunnel_type_t tnl_type,
    int *tunnel_term,
    int *tunnel_init)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_type_support_check(unit, tnl_type, tunnel_term, tunnel_init));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_control_set(
    int unit,
    bcmi_ltsw_tunnel_control_t control,
    uint32_t value)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_control_set(unit, control, value));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_control_get(
    int unit,
    bcmi_ltsw_tunnel_control_t control,
    uint32_t *value)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_control_get(unit, control, value));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_config_set(
    int unit,
    bcm_tunnel_config_t *tconfig)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_config_set(unit, tconfig));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_config_get(
    int unit,
    bcm_tunnel_config_t *tconfig)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_config_get(unit, tconfig));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_decap_port_profile_add(
    int unit,
    bcmi_ltsw_tunnel_decap_port_profile_t *entry,
    int *index)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_decap_port_profile_add(unit, entry, index));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_decap_port_profile_get(
    int unit,
    bcmi_ltsw_tunnel_decap_port_profile_t *entry,
    int index)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_decap_port_profile_get(unit, entry, index));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_decap_port_profile_delete(
    int unit,
    int index)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_decap_port_profile_delete(unit, index));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56990_a0_ltsw_tunnel_decap_port_profile_recover(
    int unit,
    int index)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (xgs_ltsw_tunnel_decap_port_profile_recover(unit, index));

exit:
    SHR_FUNC_EXIT();
}

/*!
 * \brief Tunnel driver function variable for bcm56990_a0 device.
 */
static mbcm_ltsw_tunnel_drv_t bcm56990_a0_ltsw_tunnel_drv = {
    .tunnel_init_lt_db = bcm56990_a0_ltsw_tunnel_init_lt_db,
    .tunnel_init = bcm56990_a0_ltsw_tunnel_init,
    .tunnel_free_resource = bcm56990_a0_ltsw_tunnel_free_resource,
    .tunnel_initiator_get = bcm56990_a0_ltsw_tunnel_initiator_get,
    .tunnel_initiator_traverse = bcm56990_a0_ltsw_tunnel_initiator_traverse,
    .tunnel_initiator_set = bcm56990_a0_ltsw_tunnel_initiator_set,
    .tunnel_initiator_clear = bcm56990_a0_ltsw_tunnel_initiator_clear,
    .tunnel_initiator_flexctr_object_get = bcm56990_a0_ltsw_tunnel_initiator_flexctr_object_get,
    .tunnel_terminator_add = bcm56990_a0_ltsw_tunnel_terminator_add,
    .tunnel_terminator_get = bcm56990_a0_ltsw_tunnel_terminator_get,
    .tunnel_terminator_delete = bcm56990_a0_ltsw_tunnel_terminator_delete,
    .tunnel_terminator_traverse = bcm56990_a0_ltsw_tunnel_terminator_traverse,
    .tunnel_terminator_stat_attach = bcm56990_a0_ltsw_tunnel_terminator_stat_attach,
    .tunnel_terminator_stat_detach = bcm56990_a0_ltsw_tunnel_terminator_stat_detach,
    .tunnel_terminator_flexctr_object_set = bcm56990_a0_ltsw_tunnel_terminator_flexctr_object_set,
    .tunnel_terminator_flexctr_object_get = bcm56990_a0_ltsw_tunnel_terminator_flexctr_object_get,
    .tunnel_terminator_flexctr_info_get = bcm56990_a0_ltsw_tunnel_terminator_flexctr_info_get,
    .tunnel_type_support_check = bcm56990_a0_ltsw_tunnel_type_support_check,
    .tunnel_control_set = bcm56990_a0_ltsw_tunnel_control_set,
    .tunnel_control_get = bcm56990_a0_ltsw_tunnel_control_get,
    .tunnel_config_set = bcm56990_a0_ltsw_tunnel_config_set,
    .tunnel_config_get = bcm56990_a0_ltsw_tunnel_config_get,
    .tunnel_decap_port_profile_add = bcm56990_a0_ltsw_tunnel_decap_port_profile_add,
    .tunnel_decap_port_profile_get = bcm56990_a0_ltsw_tunnel_decap_port_profile_get,
    .tunnel_decap_port_profile_delete = bcm56990_a0_ltsw_tunnel_decap_port_profile_delete,
    .tunnel_decap_port_profile_recover = bcm56990_a0_ltsw_tunnel_decap_port_profile_recover,
};

/******************************************************************************
 * Public functions
 */

int
bcm56990_a0_ltsw_tunnel_drv_attach(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (mbcm_ltsw_tunnel_drv_set(unit, &bcm56990_a0_ltsw_tunnel_drv));

    SHR_IF_ERR_VERBOSE_EXIT
        (bcm56990_a0_sub_drv_attach(unit, &bcm56990_a0_ltsw_tunnel_drv,
                                    BCM56990_A0_SUB_DRV_BCM56990_Ax,
                                    BCM56990_A0_SUB_MOD_TUNNEL));

exit:
    SHR_FUNC_EXIT();
}

/*!
 * \brief Attach functions for other members.
 */
#define BCM56990_A0_DRV_ATTACH_ENTRY(_dn,_vn,_pf,_pd,_r0) \
int _vn##_ltsw_tunnel_drv_attach(int unit) \
{ \
    SHR_FUNC_ENTER(unit); \
    SHR_IF_ERR_VERBOSE_EXIT \
        (mbcm_ltsw_tunnel_drv_set(unit, &bcm56990_a0_ltsw_tunnel_drv)); \
    SHR_IF_ERR_VERBOSE_EXIT \
        (bcm56990_a0_sub_drv_attach(unit, &bcm56990_a0_ltsw_tunnel_drv, \
                                    BCM56990_A0_SUB_DRV_BCM5699x, \
                                    BCM56990_A0_SUB_MOD_TUNNEL)); \
exit: \
    SHR_FUNC_EXIT(); \
}
#include "sub_devlist.h"