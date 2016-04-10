#include <stdio.h>

#include <netlink/netlink.h>
#include <netlink/genl/genl.h>
#include <linux/nl80211.h>

static int get_cw(struct nl_msg *msg, void *arg)
{
    struct genlmsghdr *gnlh = nlmsg_data(nlmsg_hdr(msg));
    struct nlattr *tb_msg[NL80211_ATTR_MAX + 1];
    unsigned int *wiphy = arg;

    nla_parse(tb_msg, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0), genlmsg_attrlen(gnlh, 0), NULL);

    printf("atlasd: got message!\n");

    if (tb_msg[NL80211_ATTR_UNSPEC]) printf("NL80211_ATTR_UNSPEC\n");
    if (tb_msg[NL80211_ATTR_WIPHY]) printf("NL80211_ATTR_WIPHY\n");
    if (tb_msg[NL80211_ATTR_WIPHY_NAME]) printf("NL80211_ATTR_WIPHY_NAME\n");
    if (tb_msg[NL80211_ATTR_IFINDEX]) printf("NL80211_ATTR_IFINDEX\n");
    if (tb_msg[NL80211_ATTR_IFNAME]) printf("NL80211_ATTR_IFNAME\n");
    if (tb_msg[NL80211_ATTR_IFTYPE]) printf("NL80211_ATTR_IFTYPE\n");
    if (tb_msg[NL80211_ATTR_MAC]) printf("NL80211_ATTR_MAC\n");
    if (tb_msg[NL80211_ATTR_KEY_DATA]) printf("NL80211_ATTR_KEY_DATA\n");
    if (tb_msg[NL80211_ATTR_KEY_IDX]) printf("NL80211_ATTR_KEY_IDX\n");
    if (tb_msg[NL80211_ATTR_KEY_CIPHER]) printf("NL80211_ATTR_KEY_CIPHER\n");
    if (tb_msg[NL80211_ATTR_KEY_SEQ]) printf("NL80211_ATTR_KEY_SEQ\n");
    if (tb_msg[NL80211_ATTR_KEY_DEFAULT]) printf("NL80211_ATTR_KEY_DEFAULT\n");
    if (tb_msg[NL80211_ATTR_BEACON_INTERVAL]) printf("NL80211_ATTR_BEACON_INTERVAL\n");
    if (tb_msg[NL80211_ATTR_DTIM_PERIOD]) printf("NL80211_ATTR_DTIM_PERIOD\n");
    if (tb_msg[NL80211_ATTR_BEACON_HEAD]) printf("NL80211_ATTR_BEACON_HEAD\n");
    if (tb_msg[NL80211_ATTR_BEACON_TAIL]) printf("NL80211_ATTR_BEACON_TAIL\n");
    if (tb_msg[NL80211_ATTR_STA_AID]) printf("NL80211_ATTR_STA_AID\n");
    if (tb_msg[NL80211_ATTR_STA_FLAGS]) printf("NL80211_ATTR_STA_FLAGS\n");
    if (tb_msg[NL80211_ATTR_STA_LISTEN_INTERVAL]) printf("NL80211_ATTR_STA_LISTEN_INTERVAL\n");
    if (tb_msg[NL80211_ATTR_STA_SUPPORTED_RATES]) printf("NL80211_ATTR_STA_SUPPORTED_RATES\n");
    if (tb_msg[NL80211_ATTR_STA_VLAN]) printf("NL80211_ATTR_STA_VLAN\n");
    if (tb_msg[NL80211_ATTR_STA_INFO]) printf("NL80211_ATTR_STA_INFO\n");
    if (tb_msg[NL80211_ATTR_WIPHY_BANDS]) printf("NL80211_ATTR_WIPHY_BANDS\n");
    if (tb_msg[NL80211_ATTR_MNTR_FLAGS]) printf("NL80211_ATTR_MNTR_FLAGS\n");
    if (tb_msg[NL80211_ATTR_MESH_ID]) printf("NL80211_ATTR_MESH_ID\n");
    if (tb_msg[NL80211_ATTR_STA_PLINK_ACTION]) printf("NL80211_ATTR_STA_PLINK_ACTION\n");
    if (tb_msg[NL80211_ATTR_MPATH_NEXT_HOP]) printf("NL80211_ATTR_MPATH_NEXT_HOP\n");
    if (tb_msg[NL80211_ATTR_MPATH_INFO]) printf("NL80211_ATTR_MPATH_INFO\n");
    if (tb_msg[NL80211_ATTR_BSS_CTS_PROT]) printf("NL80211_ATTR_BSS_CTS_PROT\n");
    if (tb_msg[NL80211_ATTR_BSS_SHORT_PREAMBLE]) printf("NL80211_ATTR_BSS_SHORT_PREAMBLE\n");
    if (tb_msg[NL80211_ATTR_BSS_SHORT_SLOT_TIME]) printf("NL80211_ATTR_BSS_SHORT_SLOT_TIME\n");
    if (tb_msg[NL80211_ATTR_HT_CAPABILITY]) printf("NL80211_ATTR_HT_CAPABILITY\n");
    if (tb_msg[NL80211_ATTR_SUPPORTED_IFTYPES]) printf("NL80211_ATTR_SUPPORTED_IFTYPES\n");
    if (tb_msg[NL80211_ATTR_REG_ALPHA2]) printf("NL80211_ATTR_REG_ALPHA2\n");
    if (tb_msg[NL80211_ATTR_REG_RULES]) printf("NL80211_ATTR_REG_RULES\n");
    if (tb_msg[NL80211_ATTR_MESH_CONFIG]) printf("NL80211_ATTR_MESH_CONFIG\n");
    if (tb_msg[NL80211_ATTR_BSS_BASIC_RATES]) printf("NL80211_ATTR_BSS_BASIC_RATES\n");
    if (tb_msg[NL80211_ATTR_WIPHY_TXQ_PARAMS]) printf("NL80211_ATTR_WIPHY_TXQ_PARAMS\n");
    if (tb_msg[NL80211_ATTR_WIPHY_FREQ]) printf("NL80211_ATTR_WIPHY_FREQ\n");
    if (tb_msg[NL80211_ATTR_WIPHY_CHANNEL_TYPE]) printf("NL80211_ATTR_WIPHY_CHANNEL_TYPE\n");
    if (tb_msg[NL80211_ATTR_KEY_DEFAULT_MGMT]) printf("NL80211_ATTR_KEY_DEFAULT_MGMT\n");
    if (tb_msg[NL80211_ATTR_MGMT_SUBTYPE]) printf("NL80211_ATTR_MGMT_SUBTYPE\n");
    if (tb_msg[NL80211_ATTR_IE]) printf("NL80211_ATTR_IE\n");
    if (tb_msg[NL80211_ATTR_MAX_NUM_SCAN_SSIDS]) printf("NL80211_ATTR_MAX_NUM_SCAN_SSIDS\n");
    if (tb_msg[NL80211_ATTR_SCAN_FREQUENCIES]) printf("NL80211_ATTR_SCAN_FREQUENCIES\n");
    if (tb_msg[NL80211_ATTR_SCAN_SSIDS]) printf("NL80211_ATTR_SCAN_SSIDS\n");
    if (tb_msg[NL80211_ATTR_GENERATION]) printf("NL80211_ATTR_GENERATION\n");
    if (tb_msg[NL80211_ATTR_BSS]) printf("NL80211_ATTR_BSS\n");
    if (tb_msg[NL80211_ATTR_REG_INITIATOR]) printf("NL80211_ATTR_REG_INITIATOR\n");
    if (tb_msg[NL80211_ATTR_REG_TYPE]) printf("NL80211_ATTR_REG_TYPE\n");
    if (tb_msg[NL80211_ATTR_SUPPORTED_COMMANDS]) printf("NL80211_ATTR_SUPPORTED_COMMANDS\n");
    if (tb_msg[NL80211_ATTR_FRAME]) printf("NL80211_ATTR_FRAME\n");
    if (tb_msg[NL80211_ATTR_SSID]) printf("NL80211_ATTR_SSID\n");
    if (tb_msg[NL80211_ATTR_AUTH_TYPE]) printf("NL80211_ATTR_AUTH_TYPE\n");
    if (tb_msg[NL80211_ATTR_REASON_CODE]) printf("NL80211_ATTR_REASON_CODE\n");
    if (tb_msg[NL80211_ATTR_KEY_TYPE]) printf("NL80211_ATTR_KEY_TYPE\n");
    if (tb_msg[NL80211_ATTR_MAX_SCAN_IE_LEN]) printf("NL80211_ATTR_MAX_SCAN_IE_LEN\n");
    if (tb_msg[NL80211_ATTR_CIPHER_SUITES]) printf("NL80211_ATTR_CIPHER_SUITES\n");
    if (tb_msg[NL80211_ATTR_FREQ_BEFORE]) printf("NL80211_ATTR_FREQ_BEFORE\n");
    if (tb_msg[NL80211_ATTR_FREQ_AFTER]) printf("NL80211_ATTR_FREQ_AFTER\n");
    if (tb_msg[NL80211_ATTR_FREQ_FIXED]) printf("NL80211_ATTR_FREQ_FIXED\n");
    if (tb_msg[NL80211_ATTR_WIPHY_RETRY_SHORT]) printf("NL80211_ATTR_WIPHY_RETRY_SHORT\n");
    if (tb_msg[NL80211_ATTR_WIPHY_RETRY_LONG]) printf("NL80211_ATTR_WIPHY_RETRY_LONG\n");
    if (tb_msg[NL80211_ATTR_WIPHY_FRAG_THRESHOLD]) printf("NL80211_ATTR_WIPHY_FRAG_THRESHOLD\n");
    if (tb_msg[NL80211_ATTR_WIPHY_RTS_THRESHOLD]) printf("NL80211_ATTR_WIPHY_RTS_THRESHOLD\n");
    if (tb_msg[NL80211_ATTR_TIMED_OUT]) printf("NL80211_ATTR_TIMED_OUT\n");
    if (tb_msg[NL80211_ATTR_USE_MFP]) printf("NL80211_ATTR_USE_MFP\n");
    if (tb_msg[NL80211_ATTR_STA_FLAGS2]) printf("NL80211_ATTR_STA_FLAGS2\n");
    if (tb_msg[NL80211_ATTR_CONTROL_PORT]) printf("NL80211_ATTR_CONTROL_PORT\n");
    if (tb_msg[NL80211_ATTR_TESTDATA]) printf("NL80211_ATTR_TESTDATA\n");
    if (tb_msg[NL80211_ATTR_PRIVACY]) printf("NL80211_ATTR_PRIVACY\n");
    if (tb_msg[NL80211_ATTR_DISCONNECTED_BY_AP]) printf("NL80211_ATTR_DISCONNECTED_BY_AP\n");
    if (tb_msg[NL80211_ATTR_STATUS_CODE]) printf("NL80211_ATTR_STATUS_CODE\n");
    if (tb_msg[NL80211_ATTR_CIPHER_SUITES_PAIRWISE]) printf("NL80211_ATTR_CIPHER_SUITES_PAIRWISE\n");
    if (tb_msg[NL80211_ATTR_CIPHER_SUITE_GROUP]) printf("NL80211_ATTR_CIPHER_SUITE_GROUP\n");
    if (tb_msg[NL80211_ATTR_WPA_VERSIONS]) printf("NL80211_ATTR_WPA_VERSIONS\n");
    if (tb_msg[NL80211_ATTR_AKM_SUITES]) printf("NL80211_ATTR_AKM_SUITES\n");
    if (tb_msg[NL80211_ATTR_REQ_IE]) printf("NL80211_ATTR_REQ_IE\n");
    if (tb_msg[NL80211_ATTR_RESP_IE]) printf("NL80211_ATTR_RESP_IE\n");
    if (tb_msg[NL80211_ATTR_4ADDR]) printf("NL80211_ATTR_4ADDR\n");
    if (tb_msg[NL80211_ATTR_SURVEY_INFO]) printf("NL80211_ATTR_SURVEY_INFO\n");
    if (tb_msg[NL80211_ATTR_PMKID]) printf("NL80211_ATTR_PMKID\n");
    if (tb_msg[NL80211_ATTR_MAX_NUM_PMKIDS]) printf("NL80211_ATTR_MAX_NUM_PMKIDS\n");
    if (tb_msg[NL80211_ATTR_DURATION]) printf("NL80211_ATTR_DURATION\n");
    if (tb_msg[NL80211_ATTR_COOKIE]) printf("NL80211_ATTR_COOKIE\n");
    if (tb_msg[NL80211_ATTR_WIPHY_COVERAGE_CLASS]) printf("NL80211_ATTR_WIPHY_COVERAGE_CLASS\n");
    if (tb_msg[NL80211_ATTR_TX_RATES]) printf("NL80211_ATTR_TX_RATES\n");
    if (tb_msg[NL80211_ATTR_FRAME_MATCH]) printf("NL80211_ATTR_FRAME_MATCH\n");
    if (tb_msg[NL80211_ATTR_ACK]) printf("NL80211_ATTR_ACK\n");
    if (tb_msg[NL80211_ATTR_PS_STATE]) printf("NL80211_ATTR_PS_STATE\n");
    if (tb_msg[NL80211_ATTR_CQM]) printf("NL80211_ATTR_CQM\n");
    if (tb_msg[NL80211_ATTR_LOCAL_STATE_CHANGE]) printf("NL80211_ATTR_LOCAL_STATE_CHANGE\n");
    if (tb_msg[NL80211_ATTR_AP_ISOLATE]) printf("NL80211_ATTR_AP_ISOLATE\n");
    if (tb_msg[NL80211_ATTR_WIPHY_TX_POWER_SETTING]) printf("NL80211_ATTR_WIPHY_TX_POWER_SETTING\n");
    if (tb_msg[NL80211_ATTR_WIPHY_TX_POWER_LEVEL]) printf("NL80211_ATTR_WIPHY_TX_POWER_LEVEL\n");
    if (tb_msg[NL80211_ATTR_TX_FRAME_TYPES]) printf("NL80211_ATTR_TX_FRAME_TYPES\n");
    if (tb_msg[NL80211_ATTR_RX_FRAME_TYPES]) printf("NL80211_ATTR_RX_FRAME_TYPES\n");
    if (tb_msg[NL80211_ATTR_FRAME_TYPE]) printf("NL80211_ATTR_FRAME_TYPE\n");
    if (tb_msg[NL80211_ATTR_CONTROL_PORT_ETHERTYPE]) printf("NL80211_ATTR_CONTROL_PORT_ETHERTYPE\n");
    if (tb_msg[NL80211_ATTR_CONTROL_PORT_NO_ENCRYPT]) printf("NL80211_ATTR_CONTROL_PORT_NO_ENCRYPT\n");
    if (tb_msg[NL80211_ATTR_SUPPORT_IBSS_RSN]) printf("NL80211_ATTR_SUPPORT_IBSS_RSN\n");
    if (tb_msg[NL80211_ATTR_WIPHY_ANTENNA_TX]) printf("NL80211_ATTR_WIPHY_ANTENNA_TX\n");
    if (tb_msg[NL80211_ATTR_WIPHY_ANTENNA_RX]) printf("NL80211_ATTR_WIPHY_ANTENNA_RX\n");
    if (tb_msg[NL80211_ATTR_MCAST_RATE]) printf("NL80211_ATTR_MCAST_RATE\n");
    if (tb_msg[NL80211_ATTR_OFFCHANNEL_TX_OK]) printf("NL80211_ATTR_OFFCHANNEL_TX_OK\n");
    if (tb_msg[NL80211_ATTR_BSS_HT_OPMODE]) printf("NL80211_ATTR_BSS_HT_OPMODE\n");
    if (tb_msg[NL80211_ATTR_KEY_DEFAULT_TYPES]) printf("NL80211_ATTR_KEY_DEFAULT_TYPES\n");
    if (tb_msg[NL80211_ATTR_MAX_REMAIN_ON_CHANNEL_DURATION]) printf("NL80211_ATTR_MAX_REMAIN_ON_CHANNEL_DURATION\n");
    if (tb_msg[NL80211_ATTR_MESH_SETUP]) printf("NL80211_ATTR_MESH_SETUP\n");
    if (tb_msg[NL80211_ATTR_WIPHY_ANTENNA_AVAIL_TX]) printf("NL80211_ATTR_WIPHY_ANTENNA_AVAIL_TX\n");
    if (tb_msg[NL80211_ATTR_WIPHY_ANTENNA_AVAIL_RX]) printf("NL80211_ATTR_WIPHY_ANTENNA_AVAIL_RX\n");
    if (tb_msg[NL80211_ATTR_SUPPORT_MESH_AUTH]) printf("NL80211_ATTR_SUPPORT_MESH_AUTH\n");
    if (tb_msg[NL80211_ATTR_STA_PLINK_STATE]) printf("NL80211_ATTR_STA_PLINK_STATE\n");
    if (tb_msg[NL80211_ATTR_WOWLAN_TRIGGERS]) printf("NL80211_ATTR_WOWLAN_TRIGGERS\n");
    if (tb_msg[NL80211_ATTR_WOWLAN_TRIGGERS_SUPPORTED]) printf("NL80211_ATTR_WOWLAN_TRIGGERS_SUPPORTED\n");
    if (tb_msg[NL80211_ATTR_SCHED_SCAN_INTERVAL]) printf("NL80211_ATTR_SCHED_SCAN_INTERVAL\n");
    if (tb_msg[NL80211_ATTR_INTERFACE_COMBINATIONS]) printf("NL80211_ATTR_INTERFACE_COMBINATIONS\n");
    if (tb_msg[NL80211_ATTR_SOFTWARE_IFTYPES]) printf("NL80211_ATTR_SOFTWARE_IFTYPES\n");
    if (tb_msg[NL80211_ATTR_REKEY_DATA]) printf("NL80211_ATTR_REKEY_DATA\n");
    if (tb_msg[NL80211_ATTR_MAX_NUM_SCHED_SCAN_SSIDS]) printf("NL80211_ATTR_MAX_NUM_SCHED_SCAN_SSIDS\n");
    if (tb_msg[NL80211_ATTR_MAX_SCHED_SCAN_IE_LEN]) printf("NL80211_ATTR_MAX_SCHED_SCAN_IE_LEN\n");
    if (tb_msg[NL80211_ATTR_SCAN_SUPP_RATES]) printf("NL80211_ATTR_SCAN_SUPP_RATES\n");
    if (tb_msg[NL80211_ATTR_HIDDEN_SSID]) printf("NL80211_ATTR_HIDDEN_SSID\n");
    if (tb_msg[NL80211_ATTR_IE_PROBE_RESP]) printf("NL80211_ATTR_IE_PROBE_RESP\n");
    if (tb_msg[NL80211_ATTR_IE_ASSOC_RESP]) printf("NL80211_ATTR_IE_ASSOC_RESP\n");
    if (tb_msg[NL80211_ATTR_STA_WME]) printf("NL80211_ATTR_STA_WME\n");
    if (tb_msg[NL80211_ATTR_SUPPORT_AP_UAPSD]) printf("NL80211_ATTR_SUPPORT_AP_UAPSD\n");
    if (tb_msg[NL80211_ATTR_ROAM_SUPPORT]) printf("NL80211_ATTR_ROAM_SUPPORT\n");
    if (tb_msg[NL80211_ATTR_SCHED_SCAN_MATCH]) printf("NL80211_ATTR_SCHED_SCAN_MATCH\n");
    if (tb_msg[NL80211_ATTR_MAX_MATCH_SETS]) printf("NL80211_ATTR_MAX_MATCH_SETS\n");
    if (tb_msg[NL80211_ATTR_PMKSA_CANDIDATE]) printf("NL80211_ATTR_PMKSA_CANDIDATE\n");
    if (tb_msg[NL80211_ATTR_TX_NO_CCK_RATE]) printf("NL80211_ATTR_TX_NO_CCK_RATE\n");
    if (tb_msg[NL80211_ATTR_TDLS_ACTION]) printf("NL80211_ATTR_TDLS_ACTION\n");
    if (tb_msg[NL80211_ATTR_TDLS_DIALOG_TOKEN]) printf("NL80211_ATTR_TDLS_DIALOG_TOKEN\n");
    if (tb_msg[NL80211_ATTR_TDLS_OPERATION]) printf("NL80211_ATTR_TDLS_OPERATION\n");
    if (tb_msg[NL80211_ATTR_TDLS_SUPPORT]) printf("NL80211_ATTR_TDLS_SUPPORT\n");
    if (tb_msg[NL80211_ATTR_TDLS_EXTERNAL_SETUP]) printf("NL80211_ATTR_TDLS_EXTERNAL_SETUP\n");
    if (tb_msg[NL80211_ATTR_DEVICE_AP_SME]) printf("NL80211_ATTR_DEVICE_AP_SME\n");
    if (tb_msg[NL80211_ATTR_DONT_WAIT_FOR_ACK]) printf("NL80211_ATTR_DONT_WAIT_FOR_ACK\n");
    if (tb_msg[NL80211_ATTR_FEATURE_FLAGS]) printf("NL80211_ATTR_FEATURE_FLAGS\n");
    if (tb_msg[NL80211_ATTR_PROBE_RESP_OFFLOAD]) printf("NL80211_ATTR_PROBE_RESP_OFFLOAD\n");
    if (tb_msg[NL80211_ATTR_PROBE_RESP]) printf("NL80211_ATTR_PROBE_RESP\n");
    if (tb_msg[NL80211_ATTR_DFS_REGION]) printf("NL80211_ATTR_DFS_REGION\n");
    if (tb_msg[NL80211_ATTR_DISABLE_HT]) printf("NL80211_ATTR_DISABLE_HT\n");
    if (tb_msg[NL80211_ATTR_HT_CAPABILITY_MASK]) printf("NL80211_ATTR_HT_CAPABILITY_MASK\n");
    if (tb_msg[NL80211_ATTR_NOACK_MAP]) printf("NL80211_ATTR_NOACK_MAP\n");
    if (tb_msg[NL80211_ATTR_INACTIVITY_TIMEOUT]) printf("NL80211_ATTR_INACTIVITY_TIMEOUT\n");
    if (tb_msg[NL80211_ATTR_RX_SIGNAL_DBM]) printf("NL80211_ATTR_RX_SIGNAL_DBM\n");
    if (tb_msg[NL80211_ATTR_BG_SCAN_PERIOD]) printf("NL80211_ATTR_BG_SCAN_PERIOD\n");
    if (tb_msg[NL80211_ATTR_WDEV]) printf("NL80211_ATTR_WDEV\n");
    if (tb_msg[NL80211_ATTR_USER_REG_HINT_TYPE]) printf("NL80211_ATTR_USER_REG_HINT_TYPE\n");
    if (tb_msg[NL80211_ATTR_CONN_FAILED_REASON]) printf("NL80211_ATTR_CONN_FAILED_REASON\n");
    if (tb_msg[NL80211_ATTR_SAE_DATA]) printf("NL80211_ATTR_SAE_DATA\n");
    if (tb_msg[NL80211_ATTR_VHT_CAPABILITY]) printf("NL80211_ATTR_VHT_CAPABILITY\n");
    if (tb_msg[NL80211_ATTR_SCAN_FLAGS]) printf("NL80211_ATTR_SCAN_FLAGS\n");
    if (tb_msg[NL80211_ATTR_CHANNEL_WIDTH]) printf("NL80211_ATTR_CHANNEL_WIDTH\n");
    if (tb_msg[NL80211_ATTR_CENTER_FREQ1]) printf("NL80211_ATTR_CENTER_FREQ1\n");
    if (tb_msg[NL80211_ATTR_CENTER_FREQ2]) printf("NL80211_ATTR_CENTER_FREQ2\n");
    if (tb_msg[NL80211_ATTR_P2P_CTWINDOW]) printf("NL80211_ATTR_P2P_CTWINDOW\n");
    if (tb_msg[NL80211_ATTR_P2P_OPPPS]) printf("NL80211_ATTR_P2P_OPPPS\n");
    if (tb_msg[NL80211_ATTR_LOCAL_MESH_POWER_MODE]) printf("NL80211_ATTR_LOCAL_MESH_POWER_MODE\n");
    if (tb_msg[NL80211_ATTR_ACL_POLICY]) printf("NL80211_ATTR_ACL_POLICY\n");
    if (tb_msg[NL80211_ATTR_MAC_ADDRS]) printf("NL80211_ATTR_MAC_ADDRS\n");
    if (tb_msg[NL80211_ATTR_MAC_ACL_MAX]) printf("NL80211_ATTR_MAC_ACL_MAX\n");
    if (tb_msg[NL80211_ATTR_RADAR_EVENT]) printf("NL80211_ATTR_RADAR_EVENT\n");
    if (tb_msg[NL80211_ATTR_EXT_CAPA]) printf("NL80211_ATTR_EXT_CAPA\n");
    if (tb_msg[NL80211_ATTR_EXT_CAPA_MASK]) printf("NL80211_ATTR_EXT_CAPA_MASK\n");
    if (tb_msg[NL80211_ATTR_STA_CAPABILITY]) printf("NL80211_ATTR_STA_CAPABILITY\n");
    if (tb_msg[NL80211_ATTR_STA_EXT_CAPABILITY]) printf("NL80211_ATTR_STA_EXT_CAPABILITY\n");
    if (tb_msg[NL80211_ATTR_PROTOCOL_FEATURES]) printf("NL80211_ATTR_PROTOCOL_FEATURES\n");
    if (tb_msg[NL80211_ATTR_SPLIT_WIPHY_DUMP]) printf("NL80211_ATTR_SPLIT_WIPHY_DUMP\n");
    if (tb_msg[NL80211_ATTR_DISABLE_VHT]) printf("NL80211_ATTR_DISABLE_VHT\n");
    if (tb_msg[NL80211_ATTR_VHT_CAPABILITY_MASK]) printf("NL80211_ATTR_VHT_CAPABILITY_MASK\n");
    if (tb_msg[NL80211_ATTR_MDID]) printf("NL80211_ATTR_MDID\n");
    if (tb_msg[NL80211_ATTR_IE_RIC]) printf("NL80211_ATTR_IE_RIC\n");
    if (tb_msg[NL80211_ATTR_CRIT_PROT_ID]) printf("NL80211_ATTR_CRIT_PROT_ID\n");
    if (tb_msg[NL80211_ATTR_MAX_CRIT_PROT_DURATION]) printf("NL80211_ATTR_MAX_CRIT_PROT_DURATION\n");
    if (tb_msg[NL80211_ATTR_PEER_AID]) printf("NL80211_ATTR_PEER_AID\n");
    if (tb_msg[NL80211_ATTR_COALESCE_RULE]) printf("NL80211_ATTR_COALESCE_RULE\n");
    if (tb_msg[NL80211_ATTR_CH_SWITCH_COUNT]) printf("NL80211_ATTR_CH_SWITCH_COUNT\n");
    if (tb_msg[NL80211_ATTR_CH_SWITCH_BLOCK_TX]) printf("NL80211_ATTR_CH_SWITCH_BLOCK_TX\n");
    if (tb_msg[NL80211_ATTR_CSA_IES]) printf("NL80211_ATTR_CSA_IES\n");
    if (tb_msg[NL80211_ATTR_CSA_C_OFF_BEACON]) printf("NL80211_ATTR_CSA_C_OFF_BEACON\n");
    if (tb_msg[NL80211_ATTR_CSA_C_OFF_PRESP]) printf("NL80211_ATTR_CSA_C_OFF_PRESP\n");
    if (tb_msg[NL80211_ATTR_RXMGMT_FLAGS]) printf("NL80211_ATTR_RXMGMT_FLAGS\n");
    if (tb_msg[NL80211_ATTR_STA_SUPPORTED_CHANNELS]) printf("NL80211_ATTR_STA_SUPPORTED_CHANNELS\n");
    if (tb_msg[NL80211_ATTR_STA_SUPPORTED_OPER_CLASSES]) printf("NL80211_ATTR_STA_SUPPORTED_OPER_CLASSES\n");
    if (tb_msg[NL80211_ATTR_HANDLE_DFS]) printf("NL80211_ATTR_HANDLE_DFS\n");

    if (tb_msg[NL80211_ATTR_WIPHY_TXQ_PARAMS]) {
        unsigned int cw_min = nla_get_u32(tb_msg[NL80211_TXQ_ATTR_CWMIN]);
        printf("cw_min: %u\n", cw_min);
    }

    //nl_msg_dump(msg, stdout);

    return NL_SKIP;
}

int main()
{
    /* create socket */
    struct nl_sock *sk = NULL;

    sk = nl_socket_alloc();
    genl_connect(sk);
    nl_socket_modify_cb(sk, NL_CB_VALID, NL_CB_CUSTOM, get_cw, NULL);

    /* setup message */
    int driver_id, if_index;
    struct nl_msg *msg = NULL;

    driver_id = genl_ctrl_resolve(sk, "nl80211");
    if_index = if_nametoindex("wlan0");
    msg = nlmsg_alloc();

    genlmsg_put(msg, 0, 0, driver_id, 0, 0, NL80211_CMD_GET_WIPHY, 0);
    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, if_index);

    //struct nlattr *nested;
    //nested = nla_nest_start(msg,NL80211_ATTR_WIPHY_TXQ_PARAMS);
    //NLA_PUT_U16(msg,NL80211_TXQ_ATTR_CWMIN,cw_min);
    //NLA_PUT_U16(msg,NL80211_TXQ_ATTR_CWMAX,cw_max);
    //nla_nest_end(msg,nested);

    /* send/recv/ack */
    int r;

    r = nl_send_auto_complete(sk, msg);
    printf("atlasd: nl_send_auto_complete returned %d\n", r);
    nl_recvmsgs_default(sk);
    nl_wait_for_ack(sk);

nla_put_failure: /* from NLA_PUT_* macros */
fail:
    if (sk) nl_socket_free(sk);
    if (msg) nlmsg_free(msg);
}

