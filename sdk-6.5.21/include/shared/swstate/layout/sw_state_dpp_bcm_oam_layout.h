/* 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
*/
#ifndef _SHR_sw_state_dpp_bcm_oam_H_
#define _SHR_sw_state_dpp_bcm_oam_H_


#define SW_STATE_DPP_BCM_OAM_ACC_REF_COUNTER_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_Y1731_OPCODE_TO_INTENAL_OPCODE_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ERROR_TYPE_TO_TRAP_ID_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAMP_RX_TRAP_CODE_REF_COUNT_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_TRAP_INFO_TRAP_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_TRAP_INFO_UPMEP_TRAP_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_TRAP_INFO_MIRROR_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_TRAP_INFO_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_TRAP_INFO_TRAP_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_TRAP_INFO_UPMEP_TRAP_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_TRAP_INFO_MIRROR_IDS_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_IS_INTERNALLY_ALLOCATED_MIRROR_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_CPU_TRAP_CODE_TO_MIRROR_PROFILE_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_PROG_USED_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_MEP_PE_PROFILE_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_INSTRUCTION_FUNC_IS_VALID_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_MAX_NOF_ENDP_LSTS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_IN_USE_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_FIRST_MEMBER_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_SIZE_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_FIRST_MEMBER_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_SIZE_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_OCCUPIED_ENDP_LSTS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_ENDP_LST_MAX_NOF_ENDP_LSTS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_IN_USE_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_ENDP_LSTS_ARRAY_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_OCCUPIED_ENDP_LSTS_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_MAX_NOF_ENDP_LST_MS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_IN_USE_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_INDEX_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_NEXT_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_INDEX_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_NEXT_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_OCCUPIED_ENDP_LST_MS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_ENDP_LST_M_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_MAX_NOF_ENDP_LST_MS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_IN_USE_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_ENDP_LST_MS_ARRAY_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_OCCUPIED_ENDP_LST_MS_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MA_INDEX_TO_NAME_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MA_TO_MEP_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_RMEP_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_BFD_MEP_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_BFD_MEP_TO_RMEP_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_TO_AIS_ID_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_SAT_GTF_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_SAT_CTF_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_OAM_HASHS_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MA_INDEX_TO_NAME_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MA_TO_MEP_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_RMEP_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_BFD_MEP_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_BFD_MEP_TO_RMEP_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_TO_AIS_ID_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_SAT_GTF_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS__BCM_DPP_OAM_MEP_SAT_CTF_INFO_DB_LAYOUT_NOF_MAX_LAYOUT_NODES) 
#define SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_INT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_PKT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_INNER_PKT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_NO_OF_SLM_ENDPOINTS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_NO_OF_DLM_ENDPOINTS_LAYOUT_NOF_MAX_LAYOUT_NODES (1) 
#define SW_STATE_DPP_BCM_OAM_LAYOUT_NOF_MAX_LAYOUT_NODES (1 + SW_STATE_DPP_BCM_OAM_ACC_REF_COUNTER_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_Y1731_OPCODE_TO_INTENAL_OPCODE_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ERROR_TYPE_TO_TRAP_ID_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAMP_RX_TRAP_CODE_REF_COUNT_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_TRAP_INFO_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_IS_INTERNALLY_ALLOCATED_MIRROR_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_CPU_TRAP_CODE_TO_MIRROR_PROFILE_MAP_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_PROG_USED_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_MEP_PE_PROFILE_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_INSTRUCTION_FUNC_IS_VALID_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_ENDP_LST_M_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_OAM_HASHS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_INT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_PKT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_LOOPBACK_OBJECT_INNER_PKT_PRI_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_NO_OF_SLM_ENDPOINTS_LAYOUT_NOF_MAX_LAYOUT_NODES + SW_STATE_DPP_BCM_OAM_NO_OF_DLM_ENDPOINTS_LAYOUT_NOF_MAX_LAYOUT_NODES) 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_acc_ref_counter_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_y1731_opcode_to_intenal_opcode_map_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_error_type_to_trap_id_map_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oamp_rx_trap_code_ref_count_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_trap_info_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_trap_info_trap_ids_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_trap_info_upmep_trap_ids_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_trap_info_mirror_ids_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_is_internally_allocated_mirror_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_cpu_trap_code_to_mirror_profile_map_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_prog_used_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_mep_pe_profile_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_instruction_func_is_valid_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_max_nof_endp_lsts_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_in_use_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_endp_lsts_array_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_endp_lsts_array_first_member_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_endp_lsts_array_size_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_occupied_endp_lsts_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_max_nof_endp_lst_ms_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_in_use_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_endp_lst_ms_array_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_endp_lst_ms_array_index_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_endp_lst_ms_array_next_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_endp_lst_m_occupied_endp_lst_ms_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_ma_index_to_name_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_ma_to_mep_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_rmep_info_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_bfd_mep_info_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_bfd_mep_to_rmep_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_mep_to_ais_id_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_mep_sat_gtf_info_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_oam_hashs__bcm_dpp_oam_mep_sat_ctf_info_db_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_loopback_object_int_pri_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_loopback_object_pkt_pri_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_loopback_object_inner_pkt_pri_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_no_of_slm_endpoints_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
int sw_state_dpp_bcm_oam_no_of_dlm_endpoints_layout_node_create(int unit, int* root_node_id, uint32* next_free_node_id);
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#endif /* _SHR_sw_state_dpp_bcm_oam_H_ */