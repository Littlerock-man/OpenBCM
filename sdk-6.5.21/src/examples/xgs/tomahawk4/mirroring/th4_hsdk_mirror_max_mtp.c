/*
 * Feature  : This script will test the MAX mirror sessions supported.
 *
 * Usage    : BCM.0> cint th4_hsdk_mirror_max_mtp.c
 *
 * config   : th4_hsdk_mirroring_config.yml
 *
 * Log file : th4_hsdk_mirror_max_mtp_log.txt
 *
 * Test Topology :
 *                      +-------------------+
 *                      |                   |
 *        ingress_port  |                   |  mtp_port1 (MTP)
 *       -------------->+                   +-------------->
 *        VLAN 11       |                   |
 *                      |                   |
 *                      |       TH4         |
 *                      |                   |
 *        egress_port   |                   |  mtp_port2 (MTP)
 *       <--------------+                   +-------------->
 *        VLAN 12       |                   |
 *                      |                   |
 *                      +-------------------+
 *
 *       L3 route : dip=10.58.66.0/24 ---> 100001 (PORT=egress_port)
 *
 * Summary:
 * ========
 *   Cint script to demonstrate MAX number of mirror sessions supported.
 *   Mirror the traffic ingressing on ingress_port to the mirror-to-port
 *   (mtp_port1) and traffic ingressing on egress_port to the mirror-to-port
 *   (mtp_port2).
 *
 * Detailed steps done in the CINT script:
 * =======================================
 *   1) Step1 - Test Setup (Done in test_setup()):
 *   =============================================
 *     a) Selects 4 ports and configure them in Loopback mode. Out of these
 *        4 ports, one port is used as ingress port and the other thress ports
 *        as egress ports.
 *
 *     b) Install an IFP rule to copy egress packets to CPU and start
 *        packet watcher.
 *
 *     c) Add an entry in the L3 route table for DIP "10.58.66.0/24"
 *        to route ingress packet to egress port (egress_port).
 *
 *     c) Configuration (Done in setup_mirror_scale()):
 *   =========================================================
 *       c.1) Create mirroring destination descriptor (mirror_dest_id).
 *            - Descriptor contains mirrored traffic destination (gport).
 *       c.2) Add mirroring destination to the ingress & egress port.
 *       c.3) L2 learn mode is set up on ingress and egress ports.
 *
 *   2) Step3 - Verification (Done in verify()):
 *   ===========================================
 *     a) Transmit the packet on the ingress port (ingress_port) and loopback.
 *
 *     Ingress Packet:
 *       0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
 *       0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xff, 0x01,
 *       0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00,
 *       0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
 *       0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72,
 *       0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
 *       0x68, 0x69
 *
 *     b) Expected Result:
 *     ===================
 *     The packet capture shows the egress packet transmitted on outgoing port
 *     (egress_port) as per the forwarding path setup.
 *
 *     Egress Packet 1:
 *       0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
 *       0x81, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
 *       0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
 *       0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
 *       0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
 *       0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
 *       0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *     The packet capture shows the egress packet transmitted on outgoing port
 *     (mtp_port1) as per the mirror setup.
 *
 *     Egress Packet 2:
 *       0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
 *       0x81, 0x00, 0x00, 0x0F, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
 *       0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
 *       0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
 *       0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
 *       0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
 *       0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 3:
 *       0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
 *       0x81, 0x00, 0x00, 0x10, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
 *       0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
 *       0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
 *       0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
 *       0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
 *       0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 4:
 *       0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
 *       0x81, 0x00, 0x00, 0x11, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
 *       0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
 *       0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
 *       0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
 *       0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
 *       0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 5:
 *       0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
 *       0x81, 0x00, 0x00, 0x12, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
 *       0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
 *       0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
 *       0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
 *       0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
 *       0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      The packet capture shows the egress packet transmitted on outgoing port
 *      (mtp_port2) as per the mirror setup.
 *
 *      Egress Packet 6:
 *       0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
 *       0x81, 0x00, 0x00, 0x13, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
 *       0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
 *       0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
 *       0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
 *       0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
 *       0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 7:
 *       0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
 *       0x81, 0x00, 0x00, 0x14, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
 *       0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
 *       0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
 *       0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
 *       0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
 *       0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 8:
 *       0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
 *       0x81, 0x00, 0x00, 0x15, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
 *       0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
 *       0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
 *       0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
 *       0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
 *       0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 *
 *      Egress Packet 9:
 *       0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
 *       0x81, 0x00, 0x00, 0x16, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
 *       0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
 *       0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
 *       0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
 *       0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
 *       0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69
 */

/* Reset C interpreter*/
cint_reset();

int               num_egress_ports = 3;
bcm_field_group_t group;
bcm_field_entry_t entry[num_egress_ports];
bcm_gport_t       mirror_dest_id[8];
bcm_port_t        ingress_port;
bcm_port_t        egress_port;
bcm_port_t        mtp_port1, mtp_port2;
bcm_vlan_t        vlan_in = 11;
bcm_vlan_t        vlan_out = 12;
bcm_pbmp_t        ing_pbmp, egr_pbmp;
bcm_pbmp_t        pbmp, ubmp;
uint32_t          stat_counter_id;
const uint8       priority = 101;

bcm_vlan_control_vlan_t vlan_ctrl;
bcm_l2_station_t  l2_station;
bcm_l3_ingress_t  l3_ingress;
bcm_l3_egress_t   l3_egress;
bcm_l3_route_t    route_info;
bcm_l3_intf_t     l3_intf_in, l3_intf_out;
bcm_vrf_t         vrf = 1;
bcm_mac_t         router_mac_in = {0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
bcm_mac_t         router_mac_out = {0x00, 0x00, 0x00, 0x00, 0x00, 0x02};
bcm_mac_t         dst_mac = {0x00, 0x00, 0x00, 0x00, 0xfe, 0x02};
bcm_ip_t          dip = 0x0a3a4273;
bcm_ip_t          mask = 0xffffff00;
bcm_if_t          egr_obj_id;
bcm_if_t          ingress_if = 0x1b2;
int               station_id;

unsigned char    *expected_packets[9];
bcm_pbmp_t        expected_pbmp[9];
uint32            packet_patterns = 9;
int               test_failed;         /* Final result will be stored here */
int               rx_count;            /* Global received packet count */

int               debug = 0;    /* Make it '1' to dump debug informations */

/*
 * This function checked if given port/index is already present
 * in the list so that same ports number is not generated again.
 */
int checkPortAssigned(int *port_index_list, int no_entries, int index)
{
    int                i=0;

    for (i= 0; i < no_entries; i++) {
        if (port_index_list[i] == index) {
            return 1;
        }
    }

    /* no entry found */
    return 0;
}

/*
 * This function is written so that hardcoding of port
 * numbers in Cint scripts is removed. This function gives
 * required number of ports.
 */
bcm_error_t portNumbersGet(int unit, int *port_list_ptr, int num_ports)
{
    bcm_port_config_t  configP;
    bcm_pbmp_t         ports_pbmp;
    int                tempports[BCM_PBMP_PORT_MAX];
    int                port_index_list[num_ports];
    int                i = 0, port = 0, rv = 0, index = 0;

    rv = bcm_port_config_get(unit, &configP);
    if(BCM_FAILURE(rv)) {
        printf("\nError in retrieving port configuration: %s.\n",
                bcm_errmsg(rv));
        return rv;
    }

    ports_pbmp = configP.e;
    for (i = 1; i < BCM_PBMP_PORT_MAX; i++) {
        if (BCM_PBMP_MEMBER(&ports_pbmp, i)) {
            tempports[port] = i;
            port++;
        }
    }

    if (( port == 0 ) || ( port < num_ports )) {
        printf("portNumbersGet() failed \n");
        return -1;
    }

    /* generating random ports */
    for (i= 0; i < num_ports; i++) {
        index = sal_rand()% port;
        if (checkPortAssigned(port_index_list, i, index) == 0)
        {
            port_list_ptr[i] = tempports[index];
            port_index_list[i] = index;
        } else {
            i = i - 1;
        }
    }

    return BCM_E_NONE;
}

/*
 * Configures the port in loopback mode.
 */
bcm_error_t
ingress_port_multi_setup(int unit, bcm_pbmp_t pbm)
{
    bcm_port_t         port;

    BCM_PBMP_ITER(pbm, port) {
        printf("ingress_port_multi_setup port: %d setup\n", port);
        BCM_IF_ERROR_RETURN(bcm_port_loopback_set(unit, port,
                                                  BCM_PORT_LOOPBACK_MAC));
    }

    return BCM_E_NONE;
}

/*
 * Configures the port in loopback mode and installs
 * an IFP rule. This IFP rule copies the packets ingressing
 * on the specified port to CPU. Port is also configured
 * to discard all packets. This is to avoid continuous
 * loopback of the packet from the egress port.
 */
bcm_error_t
egress_port_multi_setup(int unit, bcm_pbmp_t pbm)
{
    bcm_field_group_config_t    group_config;
    bcm_port_t                  port;
    int                         i = 0;

    bcm_field_group_config_t_init(&group_config);
    BCM_FIELD_QSET_INIT(group_config.qset);
    BCM_FIELD_QSET_ADD(group_config.qset, bcmFieldQualifyInPort);
    BCM_FIELD_QSET_ADD(group_config.qset, bcmFieldQualifyStageLookup);
    BCM_FIELD_ASET_ADD(group_config.aset, bcmFieldActionCopyToCpu);
    BCM_FIELD_ASET_ADD(group_config.aset, bcmFieldActionDrop);
    group_config.priority = 2;
    BCM_IF_ERROR_RETURN(bcm_field_group_config_create(unit, &group_config));

    group = group_config.group;

    BCM_PBMP_ITER(pbm, port) {
        printf("egress_port_multi_setup port: %d setup\n", port);

        BCM_IF_ERROR_RETURN(bcm_port_loopback_set(unit, port,
                                                  BCM_PORT_LOOPBACK_MAC));
        BCM_IF_ERROR_RETURN(bcm_field_entry_create(unit, group, &entry[i]));
        BCM_IF_ERROR_RETURN(bcm_field_qualify_InPort(unit, entry[i], port,
                                                  BCM_FIELD_EXACT_MATCH_MASK));
        BCM_IF_ERROR_RETURN(bcm_field_action_add(unit, entry[i],
                                                 bcmFieldActionCopyToCpu,
                                                 0, 0));
        BCM_IF_ERROR_RETURN(bcm_field_action_add(unit, entry[i],
                                                 bcmFieldActionDrop, 0, 0));

        BCM_IF_ERROR_RETURN(bcm_field_entry_install(unit, entry[i]));

        i++;
    }

    return BCM_E_NONE;
}

bcm_error_t
ingress_port_multi_cleanup(int unit, bcm_pbmp_t pbm)
{
    bcm_port_t         port;

    BCM_PBMP_ITER(pbm, port) {
        printf("ingress_port_multi_cleanup port: %d cleanup\n", port);
        BCM_IF_ERROR_RETURN(bcm_port_loopback_set(unit, port,
                                                  BCM_PORT_LOOPBACK_NONE));
    }

    return BCM_E_NONE;
}

bcm_error_t
egress_port_multi_cleanup(int unit, bcm_pbmp_t pbm)
{
    bcm_port_t         port;
    int                rv, i;

    rv = bcm_field_group_remove(unit, group);
    if (BCM_FAILURE(rv)) {
        printf("bcm_field_group_remove: %s\n", bcm_errmsg(rv));
        return rv;
    }

    for (i = 0; i < num_egress_ports; i++) {
        rv = bcm_field_entry_destroy(unit, entry[i]);
        if (BCM_FAILURE(rv)) {
            printf("bcm_field_entry_destroy: %s\n", bcm_errmsg(rv));
            return rv;
        }
    }

    rv = bcm_field_group_destroy(unit, group);
    if (BCM_FAILURE(rv)) {
        printf("bcm_field_group_destroy: %s\n", bcm_errmsg(rv));
        return rv;
    }

    BCM_PBMP_ITER(pbm, port) {
        printf("egress_port_multi_cleanup port: %d cleanup\n", port);
        BCM_IF_ERROR_RETURN(bcm_port_loopback_set(unit, port,
                                                  BCM_PORT_LOOPBACK_NONE));
    }

    return BCM_E_NONE;
}


/* Register callback function for received packets. */
bcm_error_t
registerPktioRxCallback(int unit)
{
    const uint32       flags = 0;      /* Flags only used on match (for now) */

    return bcm_pktio_rx_register
      (unit, "rx_cb", pktioRxCallback, priority, &rx_count, flags);
}

bcm_error_t
unregisterPktioRxCallback(int unit)
{
    return bcm_pktio_rx_unregister(unit, pktioRxCallback, priority);
}

bcm_error_t
setup_flex_ctr(int unit)
{
    bcm_flexctr_index_operation_t  *index_op = NULL;
    bcm_flexctr_value_operation_t  *value_a_op = NULL;
    bcm_flexctr_value_operation_t  *value_b_op = NULL;
    bcm_flexctr_action_t            action = {0};
    int                             options = 0, rv;

    /* Counter index is egress port. */
    index_op = &action.index_operation;
    index_op->object[0] = bcmFlexctrObjectStaticEgrEgressPort;
    index_op->mask_size[0] = 9;
    index_op->shift[0] = 0;
    index_op->object[1] = bcmFlexctrObjectConstZero;
    index_op->mask_size[1] = 1;
    index_op->shift[1] = 0;

    /* Increase counter per packet. */
    value_a_op = &action.operation_a;
    value_a_op->select = bcmFlexctrValueSelectCounterValue;
    value_a_op->object[0] = bcmFlexctrObjectConstOne;
    value_a_op->mask_size[0] = 16;
    value_a_op->shift[0] = 0;
    value_a_op->object[1] = bcmFlexctrObjectConstZero;
    value_a_op->mask_size[1] = 1;
    value_a_op->shift[1] = 0;
    value_a_op->type = bcmFlexctrValueOperationTypeInc;

    /* Increase counter per packet bytes. */
    value_b_op = &action.operation_b;
    value_b_op->select = bcmFlexctrValueSelectPacketLength;
    value_b_op->type = bcmFlexctrValueOperationTypeInc;

    action.source = bcmFlexctrSourceEgrPort;
    action.hint = 0;
    action.mode = bcmFlexctrCounterModeNormal;
    action.index_num = 512;
    /* Enable to count egress mirrored packets. */
    action.egress_mirror_count_enable=1;

    rv = bcm_flexctr_action_create(unit, options, &action, &stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_flexctr_action_create %s\n", bcm_errmsg(rv));
        return rv;
    }

    printf("stat_counter_id = 0x%x\n", stat_counter_id);

    /* Attach counter action to egress ports. */
    rv = bcm_port_stat_attach(unit, egress_port, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_vlan_stat_attach %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = bcm_port_stat_attach(unit, mtp_port1, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_vlan_stat_attach %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = bcm_port_stat_attach(unit, mtp_port2, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_vlan_stat_attach %s\n", bcm_errmsg(rv));
        return rv;
    }

    return BCM_E_NONE;
}


bcm_error_t
cleanup_flex_ctr(int unit)
{
    int                rv;

    /* Detach counter action. */
    rv = bcm_port_stat_detach_with_id(unit, egress_port, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_port_stat_detach_with_id: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = bcm_port_stat_detach_with_id(unit, mtp_port1, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_port_stat_detach_with_id: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = bcm_port_stat_detach_with_id(unit, mtp_port2, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_port_stat_detach_with_id: %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Destroy counter action. */
    rv = bcm_flexctr_action_destroy(unit, stat_counter_id);
    if (BCM_FAILURE(rv)) {
        printf("bcm_flexctr_action_destroy %s\n", bcm_errmsg(rv));
        return rv;
    }

    return BCM_E_NONE;
}


/* Mirror egress configuration. */
bcm_error_t
setup_mirror_scale (int unit)
{
    bcm_mirror_destination_t    mirror_dest[9];
    bcm_gport_t                 mtp_gport1, mtp_gport2;
    bcm_error_t                 rv = BCM_E_NONE;
    uint32                      mirror_flags = 0;
    int                         i = 0, vlan_id = 15;

    /* Get the GPORT ID for the MTP port. */
    bcm_port_gport_get(unit, mtp_port1, &mtp_gport1);
    bcm_port_gport_get(unit, mtp_port2, &mtp_gport2);

    printf("Mirror destination create - MTP=%d \n", mtp_port1);
    for (i=0; i <= 3; i++) {
        bcm_mirror_destination_t_init(&mirror_dest[i]);
        mirror_dest[i].flags  |= BCM_MIRROR_DEST_TUNNEL_L2;
        mirror_dest[i].gport   = mtp_gport1;
        mirror_dest[i].tpid    = 0x8100;
        mirror_dest[i].vlan_id = vlan_id + i;
        rv = bcm_mirror_destination_create(unit, &mirror_dest[i]);
        if(BCM_FAILURE(rv)) {
            printf("\nError in mirror dest create: %s.\n",bcm_errmsg(rv));
            return rv;
        }
        mirror_dest_id[i] = mirror_dest[i].mirror_dest_id;
        printf("Mirror destination created id = %d\n",mirror_dest_id[i]);
    }

    printf("Mirror destination create - MTP=%d \n", mtp_port2);
    for (i=4; i <= 7; i++) {
        bcm_mirror_destination_t_init(&mirror_dest[i]);
        mirror_dest[i].flags  |= BCM_MIRROR_DEST_TUNNEL_L2;
        mirror_dest[i].gport   = mtp_gport2;
        mirror_dest[i].tpid    = 0x8100;
        mirror_dest[i].vlan_id = vlan_id + i;
        rv = bcm_mirror_destination_create(unit, &mirror_dest[i]);
        if(BCM_FAILURE(rv)) {
            printf("\nError in mirror dest create: %s.\n",bcm_errmsg(rv));
            return rv;
        }
        mirror_dest_id[i] = mirror_dest[i].mirror_dest_id;
        printf("Mirror destination created id = %d\n",mirror_dest_id[i]);
    }
    bcm_mirror_destination_t_init(&mirror_dest[i]);
    mirror_dest[i].flags  |= BCM_MIRROR_DEST_TUNNEL_L2;
    mirror_dest[i].gport   = mtp_gport1;
    mirror_dest[i].tpid    = 0x8100;
    mirror_dest[i].vlan_id = vlan_id + i;
    rv = bcm_mirror_destination_create(unit, &mirror_dest[i]);
    if(BCM_SUCCESS(rv)) {
        printf("\nExpected 'No resources for operation' error but get '%s'.\n",
                                                               bcm_errmsg(rv));
        return rv;
    }

    printf("Mirror ingress port destination add\n");
    for (i=0; i <= 3; i++) {
        mirror_flags = BCM_MIRROR_PORT_INGRESS;
        print mirror_dest_id[i];
        rv = bcm_mirror_port_dest_add(unit, ingress_port,
                                      mirror_flags,
                                      mirror_dest_id[i]);
        if(BCM_FAILURE(rv)) {
            printf("\nError in ingress mirror port dest add: %s.\n",
                                                               bcm_errmsg(rv));
            return rv;
        }
    }

    printf("Mirror ingress port destination add\n");
    for (i=4; i <= 7; i++) {
        mirror_flags = BCM_MIRROR_PORT_INGRESS;
        print mirror_dest_id[i];
        rv = bcm_mirror_port_dest_add(unit, egress_port,
                                      mirror_flags,
                                      mirror_dest_id[i]);
        if(BCM_FAILURE(rv)) {
            printf("\nError in ingress mirror port dest add: %s - %d \n",
                                                           bcm_errmsg(rv),
                                                           mirror_dest_id[i]);
            return rv;
        }
    }

    /* Learn mode port config. */
    rv = port_learn_mode_set(unit, ingress_port,
                             BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Drop egress_port received packet to avoid looping back. */
    rv = port_learn_mode_set(unit, egress_port, 0);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = port_learn_mode_set(unit, mtp_port1, 0);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = port_learn_mode_set(unit, mtp_port2, 0);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    return rv;
}


/* Cleanup configurations. */
bcm_error_t
cleanup_mirror_egress(int unit)
{
    bcm_error_t                 rv = BCM_E_NONE;
    uint32                      mirror_flags = 0;
    int                         i = 0;

    for (i=0; i <= 3; i++) {
        /* Delete mirroring destination from a port. */
        mirror_flags |= BCM_MIRROR_PORT_INGRESS;
        rv = bcm_mirror_port_dest_delete(unit, ingress_port, mirror_flags,
                mirror_dest_id[i]);
        if (BCM_FAILURE(rv)) {
            printf("\nError in bcm_mirror_port_dest_delete: %s - %d \n",
                                                           bcm_errmsg(rv),
                                                           mirror_dest_id[i]);
            return rv;
        }

        /* Remove mirror destination descriptor. */
        rv = bcm_mirror_destination_destroy(unit, mirror_dest_id[i]);
        if (BCM_FAILURE(rv)) {
            printf("\nError in bcm_mirror_destination_destroy: %s - %d \n",
                                                           bcm_errmsg(rv),
                                                           mirror_dest_id[i]);
            return rv;
        }
    }

    for (i=4; i <= 7; i++) {
        /* Delete mirroring destination from a port. */
        mirror_flags |= BCM_MIRROR_PORT_INGRESS;
        rv = bcm_mirror_port_dest_delete(unit, egress_port, mirror_flags,
                mirror_dest_id[i]);
        if (BCM_FAILURE(rv)) {
            printf("\nError in bcm_mirror_port_dest_delete: %s - %d \n",
                                                           bcm_errmsg(rv),
                                                           mirror_dest_id[i]);
            return rv;
        }

        /* Remove mirror destination descriptor. */
        rv = bcm_mirror_destination_destroy(unit, mirror_dest_id[i]);
        if (BCM_FAILURE(rv)) {
            printf("\nError in bcm_mirror_destination_destroy: %s - %d \n",
                                                           bcm_errmsg(rv),
                                                           mirror_dest_id[i]);
            return rv;
        }
    }

    /* Restore Learn mode port config. */
    rv = port_learn_mode_set(unit, ingress_port,
                             BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = port_learn_mode_set(unit, egress_port,
                             BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD);
    if (BCM_FAILURE(rv)) {
        printf("\nError in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = port_learn_mode_set(unit, mtp_port1,
                             BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD);
    if (BCM_FAILURE(rv)) {
        printf("\nerror in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = port_learn_mode_set(unit, mtp_port2,
                             BCM_PORT_LEARN_ARL | BCM_PORT_LEARN_FWD);
    if (BCM_FAILURE(rv)) {
        printf("\nerror in port_learn_mode_set: %s\n", bcm_errmsg(rv));
        return rv;
    }

    return rv;
}

/*
 * Test Setup:
 * This functions gets the port numbers and sets up ingress and
 * egress ports. Check ingress_port_setup() and egress_port_setup().
 */
bcm_error_t
test_setup(int unit)
{
    bcm_mac_t          dst_mac = "00:00:00:00:00:22";
    int                num_ports = 4;
    int                port_list[num_ports];
    int                rv;

    if (BCM_E_NONE != portNumbersGet(unit, port_list, num_ports)) {
        printf("portNumbersGet() failed\n");
        return -1;
    }

    ingress_port = port_list[0];
    egress_port = port_list[1];
    mtp_port1 = port_list[2];
    mtp_port2 = port_list[3];

    printf("Ingress port : %d\n", ingress_port);
    printf("Egress port1: %d\n", egress_port);
    printf("MTP port1: %d\n", mtp_port1);
    printf("MTP port2: %d\n", mtp_port2);

    /* Enable IPv4 on PORT */
    print bcm_port_control_set(unit, ingress_port, bcmPortControlIP4, 1);

    /* Create ingress vlan and add port to vlan */
    BCM_PBMP_CLEAR(ubmp);
    BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_PORT_ADD(pbmp, ingress_port);
    print bcm_vlan_create(unit, vlan_in);
    print bcm_vlan_port_add(unit, vlan_in, pbmp, ubmp);

    /* Create egress vlan and add port to vlan */
    BCM_PBMP_CLEAR(ubmp);
    BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_PORT_ADD(pbmp, egress_port);
    BCM_PBMP_PORT_ADD(pbmp, 0); /* Added CPU port to same vlan. */
    print bcm_vlan_create(unit, vlan_out);
    print bcm_vlan_port_add(unit, vlan_out, pbmp, ubmp);

    /* Set port default VLAN for the port */
    BCM_IF_ERROR_RETURN(bcm_port_untagged_vlan_set(unit, ingress_port,
                                                   vlan_in));
    BCM_IF_ERROR_RETURN(bcm_port_untagged_vlan_set(unit, egress_port,
                                                   vlan_out));

    BCM_PBMP_CLEAR(ing_pbmp);
    BCM_PBMP_PORT_ADD(ing_pbmp, ingress_port);
    if (BCM_E_NONE != ingress_port_multi_setup(unit, ing_pbmp)) {
        printf("ingress_port_multi_setup() failed for port %d\n", ingress_port);
        return -1;
    }

    BCM_PBMP_CLEAR(egr_pbmp);
    BCM_PBMP_PORT_ADD(egr_pbmp, egress_port);
    BCM_PBMP_PORT_ADD(egr_pbmp, mtp_port1);
    BCM_PBMP_PORT_ADD(egr_pbmp, mtp_port2);
    if (BCM_E_NONE != egress_port_multi_setup(unit, egr_pbmp)) {
        printf("egress_port_multi_setup() failed for port %d\n", egress_port);
        return -1;
    }

    bshell(unit, "pw start report +raw +decode");

    rv = registerPktioRxCallback(unit);
    if (BCM_FAILURE(rv)) {
        printf("registerPktioRxCallback() FAILED: %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Configure L3 unicast for forwarding. */
    rv = l3_route_uc_create(unit);
    if (BCM_FAILURE(rv)) {
        printf("\nError in l3_route_uc_create: %s\n", bcm_errmsg(rv));
        return rv;
    }

    if (BCM_E_NONE != setup_mirror_scale(unit)) {
        printf("setup_mirror_scale() failed.\n");
        return -1;
    }

    if (BCM_E_NONE != setup_flex_ctr(unit)) {
        printf("setup_flex_ctr() failed.\n");
        return -1;
    }

    return BCM_E_NONE;
}


/*
 * Clean up pre-test setup.
 */
int test_cleanup(int unit)
{
    if (BCM_E_NONE != cleanup_flex_ctr(unit)) {
        printf("cleanup_flex_ctr() failed.\n");
        return -1;
    }

    if (BCM_E_NONE != cleanup_mirror_egress(unit)) {
        printf("cleanup_mirror_egress() failed.\n");
        return -1;
    }

    /* Delete an entry from L2 station Table */
    BCM_IF_ERROR_RETURN(bcm_l2_station_delete(unit, station_id));

    /* Delete the route for DIP */
    bcm_l3_route_t_init(&route_info);
    route_info.l3a_intf = egr_obj_id;
    route_info.l3a_subnet = dip;
    route_info.l3a_ip_mask = mask;
    route_info.l3a_vrf = vrf;
    BCM_IF_ERROR_RETURN(bcm_l3_route_delete(unit, &route_info));

    /* Destroy an egress forwarding object */
    BCM_IF_ERROR_RETURN(bcm_l3_egress_destroy(unit, egr_obj_id));

    /* Destroy l3 ingress interface object */
    BCM_IF_ERROR_RETURN(bcm_l3_ingress_destroy(unit, ingress_if));

    /* Delete L3 interfaces */
    BCM_IF_ERROR_RETURN(bcm_l3_intf_delete(unit, &l3_intf_in));
    BCM_IF_ERROR_RETURN(bcm_l3_intf_delete(unit, &l3_intf_out));

    /* Clean up learned L2 entries. */
    BCM_IF_ERROR_RETURN(bcm_l2_addr_delete_by_vlan(unit, vlan_in, 0));
    BCM_IF_ERROR_RETURN(bcm_l2_addr_delete_by_vlan(unit, vlan_out, 0));

    /* Set default vlan. */
    BCM_IF_ERROR_RETURN(bcm_port_untagged_vlan_set(unit, ingress_port, 1));
    BCM_IF_ERROR_RETURN(bcm_port_untagged_vlan_set(unit, egress_port, 1));

    /* Delete vlan. */
    BCM_IF_ERROR_RETURN(bcm_vlan_destroy(unit, vlan_in));
    BCM_IF_ERROR_RETURN(bcm_vlan_destroy(unit, vlan_out));

    BCM_IF_ERROR_RETURN(ingress_port_multi_cleanup(unit, ing_pbmp));
    BCM_IF_ERROR_RETURN(egress_port_multi_cleanup(unit, egr_pbmp));

    bshell(unit, "pw stop");
    unregisterPktioRxCallback(unit);

    return BCM_E_NONE;
}

bcm_error_t
l3_route_uc_create(int unit)
{

    /* create l3 interface */
    bcm_l3_intf_t_init(&l3_intf_in);
    sal_memcpy(l3_intf_in.l3a_mac_addr, router_mac_in, sizeof(router_mac_in));
    l3_intf_in.l3a_vid = vlan_in;
    BCM_IF_ERROR_RETURN(bcm_l3_intf_create(unit, &l3_intf_in));

    bcm_l3_intf_t_init(&l3_intf_out);
    sal_memcpy(l3_intf_out.l3a_mac_addr, router_mac_out,
               sizeof(router_mac_out));
    l3_intf_out.l3a_vid = vlan_out;
    BCM_IF_ERROR_RETURN(bcm_l3_intf_create(unit, &l3_intf_out));

    /* create l3 ingress interface */
    bcm_l3_ingress_t_init(&l3_ingress);
    l3_ingress.flags = BCM_L3_INGRESS_WITH_ID;
    l3_ingress.vrf = vrf;
    BCM_IF_ERROR_RETURN(bcm_l3_ingress_create(unit, &l3_ingress, &ingress_if));

    /* Config vlan_id to l3_iif mapping */
    bcm_vlan_control_vlan_t_init(&vlan_ctrl);
    bcm_vlan_control_vlan_get(unit, vlan_in, &vlan_ctrl);
    vlan_ctrl.ingress_if = ingress_if;
    BCM_IF_ERROR_RETURN(bcm_vlan_control_vlan_set(unit, vlan_in, vlan_ctrl));

    /* Create L3 egress object */
    bcm_l3_egress_t_init(&l3_egress);
    sal_memcpy(l3_egress.mac_addr, dst_mac, sizeof(dst_mac));
    l3_egress.port = egress_port;
    l3_egress.intf = l3_intf_out.l3a_intf_id;
    BCM_IF_ERROR_RETURN(bcm_l3_egress_create(unit, 0, &l3_egress, &egr_obj_id));
    print egr_obj_id;

    /* Install the route for DIP */
    bcm_l3_route_t_init(&route_info);
    route_info.l3a_intf = egr_obj_id;
    route_info.l3a_subnet = dip;
    route_info.l3a_ip_mask = mask;
    route_info.l3a_vrf = vrf;
    BCM_IF_ERROR_RETURN(bcm_l3_route_add(unit, &route_info));

    /* Config my station */
    bcm_l2_station_t_init(&l2_station);
    sal_memcpy(l2_station.dst_mac, router_mac_in, sizeof(router_mac_in));
    l2_station.dst_mac_mask = "ff:ff:ff:ff:ff:ff";
    l2_station.flags = BCM_L2_STATION_IPV4 | BCM_L2_STATION_IPV6;
    BCM_IF_ERROR_RETURN(bcm_l2_station_add(unit, &station_id, &l2_station));

    return BCM_E_NONE;
}

/* Static L2 entry for forwarding. */
bcm_error_t
add_l2_static_entry(int unit, uint32 flag, bcm_mac_t mac, bcm_vpn_t vpn_id,
                    bcm_port_t port)
{
    bcm_l2_addr_t l2_addr;
    bcm_l2_addr_t_init(&l2_addr, mac, vpn_id);
    l2_addr.flags = BCM_L2_STATIC | flag;
    l2_addr.port = port;
    return bcm_l2_addr_add(unit, &l2_addr);
}

/* Setup learning on port. */
bcm_error_t
port_learn_mode_set(int unit, bcm_port_t port, uint32 flags)
{
    bcm_error_t        rv = BCM_E_NONE;

    rv = bcm_port_control_set(unit, port, bcmPortControlL2Learn, flags);
    if (BCM_FAILURE(rv)) {
        printf("Error in bcm_port_control_set(L2Learn): %s\n", bcm_errmsg(rv));
        return rv;
    }

    rv = bcm_port_control_set(unit, port, bcmPortControlL2Move, flags);
    if (BCM_FAILURE(rv)) {
        printf("Error in bcm_port_control_set(L2Move): %s\n", bcm_errmsg(rv));
        return rv;
    }

    return BCM_E_NONE;
}


/* Rx callback function for applications using the HSDK PKTIO. */
bcm_pktio_rx_t
pktioRxCallback(int unit, bcm_pktio_pkt_t * packet, void *cookie)
{
    int                i, *count = (auto) cookie;
    void              *buffer;
    uint32             length;
    bcm_port_t         src_port;
    uint32             port;

    /* Get basic packet info. */
    if (BCM_FAILURE(bcm_pktio_pkt_data_get(unit, packet, (void *) &buffer,
                                           &length))) {
        return BCM_PKTIO_RX_NOT_HANDLED;
    }

    /* Get source port metadata. */
    BCM_IF_ERROR_RETURN(bcm_pktio_pmd_field_get (unit, packet,
                                                 bcmPktioPmdTypeRx,
                                                 BCM_PKTIO_RXPMD_SRC_PORT_NUM,
                                                 &port));

    printf("pktioRxCallback: received from port 0x%x\n", port);

    src_port = port;

    for (i = 0; i < packet_patterns; i++) {
        if ((sal_memcmp(buffer, expected_packets[i], length) == 0) &&
            BCM_PBMP_MEMBER(expected_pbmp[i], src_port)) {

            (*count)++; /* Bump up the rx count */
            printf("pktioRxCallback: rx_count = 0x%x\n", *count);

            /* Remove from bitmap to make sure no duplicates. */
            BCM_PBMP_PORT_REMOVE(expected_pbmp[i], src_port);
        }
    }
    if ((i == packet_patterns) && (count == 0)) {
        test_failed = 1;   /* An unexpected packet. */
    }

    return BCM_PKTIO_RX_NOT_HANDLED;
}


/*Expected egress packets */
unsigned char expected_egress_packet1[78] = {
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x81, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
        0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
        0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
        0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
        0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet2[78] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
        0x81, 0x00, 0x00, 0x0F, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
        0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
        0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
        0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
        0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet3[78] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
        0x81, 0x00, 0x00, 0x10, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
        0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
        0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
        0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
        0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet4[78] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
        0x81, 0x00, 0x00, 0x11, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
        0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
        0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
        0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
        0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet5[78] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x2a, 0x10, 0x77, 0x77, 0x00,
        0x81, 0x00, 0x00, 0x12, 0x08, 0x00, 0x45, 0x00, 0x00, 0x3c, 0x67, 0x62,
        0x00, 0x00, 0xff, 0x01, 0xbd, 0x76, 0x0a, 0x3a, 0x40, 0x01, 0x0a, 0x3a,
        0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01, 0x00, 0x51, 0x61, 0x62,
        0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x61, 0x62, 0x63,
        0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet6[82] = {
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x81, 0x00, 0x00, 0x13, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
        0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
        0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
        0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
        0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
        0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet7[82] = {
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x81, 0x00, 0x00, 0x14, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
        0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
        0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
        0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
        0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
        0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet8[82] = {
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x81, 0x00, 0x00, 0x15, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
        0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
        0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
        0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
        0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
        0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

unsigned char expected_egress_packet9[82] = {
        0x00, 0x00, 0x00, 0x00, 0xfe, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
        0x81, 0x00, 0x00, 0x16, 0x81, 0x00, 0x00, 0x0C, 0x08, 0x00, 0x45, 0x00,
        0x00, 0x3c, 0x67, 0x62, 0x00, 0x00, 0xfe, 0x01, 0xbe, 0x76, 0x0a, 0x3a,
        0x40, 0x01, 0x0a, 0x3a, 0x42, 0x73, 0x00, 0x00, 0x55, 0x0a, 0x00, 0x01,
        0x00, 0x51, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6a,
        0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
        0x77, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69};

/*
 * This function does the following.
 * Transmit the below packet on ingress_port and verify.
 */
bcm_error_t testVerify(int unit)
{
    bcm_flexctr_counter_value_t counter_value;
    char                        str[512];
    uint32                      num_entries = 1;
    uint32                      counter_index;
    int                         expected_rx_count, pass;
    int                         flexCtr_pass = 1;
    int                         count = 1;
    int                         count_mtp = 4;
    int                         length = 78;
    int                         length_mtp1 = 78;
    int                         length_mtp2 = 82;
    int                         rv;

    rx_count = 0;
    test_failed = 0;
    expected_rx_count = 9;

    expected_packets[0] = expected_egress_packet1;
    expected_packets[1] = expected_egress_packet2;
    expected_packets[2] = expected_egress_packet3;
    expected_packets[3] = expected_egress_packet4;
    expected_packets[4] = expected_egress_packet5;
    expected_packets[5] = expected_egress_packet6;
    expected_packets[6] = expected_egress_packet7;
    expected_packets[7] = expected_egress_packet8;
    expected_packets[8] = expected_egress_packet9;

    BCM_PBMP_CLEAR(expected_pbmp[0]);
    BCM_PBMP_PORT_ADD(expected_pbmp[0], egress_port);
    BCM_PBMP_CLEAR(expected_pbmp[1]);
    BCM_PBMP_PORT_ADD(expected_pbmp[1], mtp_port1);
    BCM_PBMP_CLEAR(expected_pbmp[2]);
    BCM_PBMP_PORT_ADD(expected_pbmp[2], mtp_port1);
    BCM_PBMP_CLEAR(expected_pbmp[3]);
    BCM_PBMP_PORT_ADD(expected_pbmp[3], mtp_port1);
    BCM_PBMP_CLEAR(expected_pbmp[4]);
    BCM_PBMP_PORT_ADD(expected_pbmp[4], mtp_port1);
    BCM_PBMP_CLEAR(expected_pbmp[5]);
    BCM_PBMP_PORT_ADD(expected_pbmp[5], mtp_port2);
    BCM_PBMP_CLEAR(expected_pbmp[6]);
    BCM_PBMP_PORT_ADD(expected_pbmp[6], mtp_port2);
    BCM_PBMP_CLEAR(expected_pbmp[7]);
    BCM_PBMP_PORT_ADD(expected_pbmp[7], mtp_port2);
    BCM_PBMP_CLEAR(expected_pbmp[8]);
    BCM_PBMP_PORT_ADD(expected_pbmp[8], mtp_port2);

    if (debug) {
        bshell(unit, "mirror show");
        bshell(unit, "dump sw mirror");
        bshell(unit, "bsh -c 'lt MIRROR_CONTROL traverse -l'");
    }

    printf("Verify known L3 unicast pkt from port %d forwarding to the egress port %d \n",
                                   ingress_port, egress_port);
    snprintf(str, 512, "tx %d pbm=%d data=0x000000000001002a1077770008004500003c67620000ff01bd760a3a40010a3a42730000550a000100516162636465666768696a6b6c6d6e6f7071727374757677616263646566676869; sleep quiet 3",count, ingress_port);
    bshell(unit, str);

    /* Get counter value for egress_port */
    sal_memset(&counter_value, 0, sizeof(counter_value));
    counter_index = egress_port;
    rv = bcm_flexctr_stat_sync_get(unit,
                                   stat_counter_id,
                                   num_entries,
                                   &counter_index,
                                   &counter_value);
    if (BCM_FAILURE(rv)) {
        printf("bcm_flexctr_stat_get %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Print counter value. */
    printf("FlexCtr Get on port_egress1 : %d packets / %d bytes\n",
           COMPILER_64_LO(counter_value.value[0]),
           COMPILER_64_LO(counter_value.value[1]));
    if (COMPILER_64_LO(counter_value.value[0]) != count) {
        printf("Egress_port: Packet verify failed. Expected packet stat %d but get %d\n",
                                   count,
                                   COMPILER_64_LO(counter_value.value[0]));
        flexCtr_pass = 0;
    };
    if (COMPILER_64_LO(counter_value.value[1]) != (length+4)) {
        printf("Egress_port: Packet verify failed. Expected bytes stat %d but get %d\n",
                                   (length+4),
                                   COMPILER_64_LO(counter_value.value[1]));
        flexCtr_pass = 0;
    };

    /* Get counter value for mtp_port1. */
    sal_memset(&counter_value, 0, sizeof(counter_value));
    counter_index = mtp_port1;
    rv = bcm_flexctr_stat_sync_get(unit,
                                   stat_counter_id,
                                   num_entries,
                                   &counter_index,
                                   &counter_value);
    if (BCM_FAILURE(rv)) {
        printf("bcm_flexctr_stat_get %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Print counter value. */
    printf("FlexCtr Get on port_mtp_port1 : %d packets / %d bytes\n",
                                   COMPILER_64_LO(counter_value.value[0]),
                                   COMPILER_64_LO(counter_value.value[1]));

    if (COMPILER_64_LO(counter_value.value[0]) != count_mtp) {
        printf("mtp_port1: Packet verify failed. Expected packet stat %d but get %d\n",
                                   count_mtp,
                                   COMPILER_64_LO(counter_value.value[0]));
        flexCtr_pass = 0;
    }

    if (COMPILER_64_LO(counter_value.value[1]) != ((length_mtp1+4))*count_mtp) {
        printf("mtp_port1: Packet verify failed. Expected bytes stat %d but get %d\n",
                                   ((length_mtp1+4)*count_mtp),
                                   COMPILER_64_LO(counter_value.value[1]));
        flexCtr_pass = 0;
    }

    /* Get counter value for mtp_port2. */
    sal_memset(&counter_value, 0, sizeof(counter_value));
    counter_index = mtp_port2;
    rv = bcm_flexctr_stat_sync_get(unit,
                                   stat_counter_id,
                                   num_entries,
                                   &counter_index,
                                   &counter_value);
    if (BCM_FAILURE(rv)) {
        printf("bcm_flexctr_stat_get %s\n", bcm_errmsg(rv));
        return rv;
    }

    /* Print counter value. */
    printf("FlexCtr Get on port_mtp_port2 : %d packets / %d bytes\n",
                                   COMPILER_64_LO(counter_value.value[0]),
                                   COMPILER_64_LO(counter_value.value[1]));

    if (COMPILER_64_LO(counter_value.value[0]) != count_mtp) {
        printf("mtp_port2: Packet verify failed. Expected packet stat %d but get %d\n",
                                   count_mtp,
                                   COMPILER_64_LO(counter_value.value[0]));
        flexCtr_pass = 0;
    }

    if (COMPILER_64_LO(counter_value.value[1]) != ((length_mtp2+4))*count_mtp) {
        printf("mtp_port2: Packet verify failed. Expected bytes stat %d but get %d\n",
                                   ((length_mtp2+4)*count_mtp),
                                   COMPILER_64_LO(counter_value.value[1]));
        flexCtr_pass = 0;
    }

    pass = ((test_failed == 0) && (rx_count == expected_rx_count) &&
            (flexCtr_pass));
    printf("\n----------------------------------------------------------- \n");
    printf("    RESULT OF EGRESS MIRROR VERIFICATION  ");
    printf("\n----------------------------------------------------------- \n");
    printf("Test = [%s]", pass? "PASS":"FAIL");
    printf("\n------------------------------------- \n");

    if (pass)
        return BCM_E_NONE;
    else
        return BCM_E_FAIL;
}


/*
 * execute:
 *  This function does the following
 *  a) Test setup
 *  b) Actual configuration (done in setup_mirror_scale())
 *  c) Demonstrates the functionality (done in verify())
 */
bcm_error_t
execute(void)
{
    int                unit = 0;
    int                rv;

    if (debug) {
        bshell(unit, "config show; attach ; version");
    }

    print "~~~ #1) test_setup(): ** start **";
    if (BCM_FAILURE((rv = test_setup(unit)))) {
        printf("test_setup() failed.\n");
        return -1;
    }
    print "~~~ #1) test_setup(): ** end **";

    print "~~~ #2) verify(): ** start **";
    testVerify(unit);
    print "~~~ #2) verify(): ** end **";

    print "~~~ #3) test_cleanup(): ** start **";
    if (BCM_FAILURE((rv = test_cleanup(unit)))) {
        printf("test_cleanup() failed.\n");
        return -1;
    }
    print "~~~ #3) test_cleanup(): ** end **";

    return BCM_E_NONE;
}

const char *auto_execute = (ARGC == 1) ? ARGV[0] : "YES";
if (!sal_strcmp(auto_execute, "YES")) {
    print "execute(): Start";
    print execute();
    print "execute(): End";
}