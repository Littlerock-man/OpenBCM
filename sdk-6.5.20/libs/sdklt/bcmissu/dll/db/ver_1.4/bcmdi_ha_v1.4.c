/*************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by HA parser from YAML formated file.
 * Edits to this file will be lost when it is regenerated.
 * Tool: bcmha/scripts/issu_db_gen.py
 *
 * $Copyright:.$
 *
 *************************************************************************/

#include <bcmissu/issu_types.h>
#include "bcmdi_ha.h"

static const issu_field_t bcmissu_fields_dvc_ha_info_t[] = {
    {
        .fid = 0x2430fe39,
        .width = sizeof(bool),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x75e7e28e,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_CHIP_ID_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x89ed182c,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_CHIP_REV_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x6f860561,
        .width = sizeof(uint32_t),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x4a59dacd,
        .width = sizeof(uint32_t),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x077e8b2b,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DESC_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
};

static uint32_t dvc_ha_info_t_field_offset_get (bcmissu_field_id_t field_id)
{
    dvc_ha_info_t var;

    switch (field_id) {
        case 0x2430fe39:
            return ((uint8_t *)&var.loaded) - (uint8_t *)&var;
        case 0x75e7e28e:
            return ((uint8_t *)&var.chip_id) - (uint8_t *)&var;
        case 0x89ed182c:
            return ((uint8_t *)&var.chip_rev) - (uint8_t *)&var;
        case 0x6f860561:
            return ((uint8_t *)&var.fid) - (uint8_t *)&var;
        case 0x4a59dacd:
            return ((uint8_t *)&var.entry_num) - (uint8_t *)&var;
        case 0x077e8b2b:
            return ((uint8_t *)&var.desc) - (uint8_t *)&var;
        default:
            return ISSU_INVALID_FLD_OFFSET;
    }
}

const issu_struct_t bcmissu_struct_bcmdi_ha_dvc_ha_info_t_v1_4 = {
    .offset_get_func = dvc_ha_info_t_field_offset_get,
    .generic_size = sizeof(dvc_ha_info_t),
    .field_count = 6,
    .fields = bcmissu_fields_dvc_ha_info_t,
};

static const issu_field_t bcmissu_fields_flc_ha_info_t[] = {
    {
        .fid = 0x2430fe39,
        .width = sizeof(bool),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x910955a9,
        .width = sizeof(bool),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x915c3615,
        .width = sizeof(uint32_t),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0xa9b310a1,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_FID_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x4a59dacd,
        .width = sizeof(uint32_t),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = false,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .size = 0,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x75e7e28e,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_CHIP_ID_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x89ed182c,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_CHIP_REV_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0xd9bd79bc,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DEFAULT_STR_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x3becc9a4,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DEFAULT_STR_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0xae349e2e,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DEFAULT_STR_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x17905821,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DEFAULT_STR_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x082d5c9a,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DEFAULT_STR_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
    {
        .fid = 0x077e8b2b,
        .width = sizeof(char),
        .ha_ptr = HA_PTR_NONE,
        .lt_attrib = HA_LT_NONE,
        .ltid_var_for_fid = ISSU_INVALID_FIELD_ID,
        .is_array = true,
        .size = BCMDI_DESC_BYTES,
        .var_size_id = ISSU_INVALID_FIELD_ID,
        .struct_id = ISSU_INVALID_STRUCT_ID,
        .is_local_enum = false,
        .enum_type_name = NULL,
    },
};

static uint32_t flc_ha_info_t_field_offset_get (bcmissu_field_id_t field_id)
{
    flc_ha_info_t var;

    switch (field_id) {
        case 0x2430fe39:
            return ((uint8_t *)&var.loaded) - (uint8_t *)&var;
        case 0x910955a9:
            return ((uint8_t *)&var.be) - (uint8_t *)&var;
        case 0x915c3615:
            return ((uint8_t *)&var.f_size) - (uint8_t *)&var;
        case 0xa9b310a1:
            return ((uint8_t *)&var.fid) - (uint8_t *)&var;
        case 0x4a59dacd:
            return ((uint8_t *)&var.entry_num) - (uint8_t *)&var;
        case 0x75e7e28e:
            return ((uint8_t *)&var.chip_id) - (uint8_t *)&var;
        case 0x89ed182c:
            return ((uint8_t *)&var.chip_rev) - (uint8_t *)&var;
        case 0xd9bd79bc:
            return ((uint8_t *)&var.app) - (uint8_t *)&var;
        case 0x3becc9a4:
            return ((uint8_t *)&var.app_ver) - (uint8_t *)&var;
        case 0xae349e2e:
            return ((uint8_t *)&var.app_build_time) - (uint8_t *)&var;
        case 0x17905821:
            return ((uint8_t *)&var.pid) - (uint8_t *)&var;
        case 0x082d5c9a:
            return ((uint8_t *)&var.ncs_ver) - (uint8_t *)&var;
        case 0x077e8b2b:
            return ((uint8_t *)&var.desc) - (uint8_t *)&var;
        default:
            return ISSU_INVALID_FLD_OFFSET;
    }
}

const issu_struct_t bcmissu_struct_bcmdi_ha_flc_ha_info_t_v1_4 = {
    .offset_get_func = flc_ha_info_t_field_offset_get,
    .generic_size = sizeof(flc_ha_info_t),
    .field_count = 13,
    .fields = bcmissu_fields_flc_ha_info_t,
};