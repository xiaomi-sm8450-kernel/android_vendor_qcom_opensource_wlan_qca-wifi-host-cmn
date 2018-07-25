/*
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: This file contains definitions of Data Path configuration.
 */

#ifndef _CFG_DP_H_
#define _CFG_DP_H_

#include "cfg_define.h"

#define WLAN_CFG_MAX_CLIENTS 64
#define WLAN_CFG_MAX_CLIENTS_MIN 64
#define WLAN_CFG_MAX_CLIENTS_MAX 64

/* Change this to a lower value to enforce scattered idle list mode */
#define WLAN_CFG_MAX_ALLOC_SIZE 0x200000
#define WLAN_CFG_MAX_ALLOC_SIZE_MIN 0x200000
#define WLAN_CFG_MAX_ALLOC_SIZE_MAX 0x200000

#define WLAN_CFG_NUM_TCL_DATA_RINGS 3
#define WLAN_CFG_NUM_TCL_DATA_RINGS_MIN 3
#define WLAN_CFG_NUM_TCL_DATA_RINGS_MAX 3

#ifdef CONFIG_MCL
#ifdef IPA_OFFLOAD
#define WLAN_CFG_PER_PDEV_TX_RING 0
#else
#define WLAN_CFG_PER_PDEV_TX_RING 1
#endif
#else
#define WLAN_CFG_PER_PDEV_TX_RING 0
#endif

#define WLAN_CFG_PER_PDEV_TX_RING_MIN 0
#define WLAN_CFG_PER_PDEV_TX_RING_MAX 1

#ifdef CONFIG_MCL
#define WLAN_CFG_PER_PDEV_RX_RING 0
#define WLAN_CFG_PER_PDEV_LMAC_RING 0
#define WLAN_LRO_ENABLE 1
#ifdef IPA_OFFLOAD
#define WLAN_CFG_TX_RING_SIZE 2048
#else
#define WLAN_CFG_TX_RING_SIZE 512
#endif
#define WLAN_CFG_TX_COMP_RING_SIZE 1024

/* Tx Descriptor and Tx Extension Descriptor pool sizes */
#define WLAN_CFG_NUM_TX_DESC  1024
#define WLAN_CFG_NUM_TX_EXT_DESC 1024

/* Interrupt Mitigation - Batch threshold in terms of number of frames */
#define WLAN_CFG_INT_BATCH_THRESHOLD_TX 1
#define WLAN_CFG_INT_BATCH_THRESHOLD_RX 1
#define WLAN_CFG_INT_BATCH_THRESHOLD_OTHER 1

/* Interrupt Mitigation - Timer threshold in us */
#define WLAN_CFG_INT_TIMER_THRESHOLD_TX 8
#define WLAN_CFG_INT_TIMER_THRESHOLD_RX 8
#define WLAN_CFG_INT_TIMER_THRESHOLD_OTHER 8
#endif

#ifdef CONFIG_WIN
#define WLAN_CFG_PER_PDEV_RX_RING 0
#define WLAN_CFG_PER_PDEV_LMAC_RING 1
#define WLAN_LRO_ENABLE 0

/* Tx Descriptor and Tx Extension Descriptor pool sizes */
#define WLAN_CFG_NUM_TX_DESC  0x320000
#define WLAN_CFG_NUM_TX_EXT_DESC 0x80000

/* Interrupt Mitigation - Batch threshold in terms of number of frames */
#define WLAN_CFG_INT_BATCH_THRESHOLD_TX 256
#define WLAN_CFG_INT_BATCH_THRESHOLD_RX 128
#define WLAN_CFG_INT_BATCH_THRESHOLD_OTHER 1

/* Interrupt Mitigation - Timer threshold in us */
#define WLAN_CFG_INT_TIMER_THRESHOLD_TX 1000
#define WLAN_CFG_INT_TIMER_THRESHOLD_RX 500
#define WLAN_CFG_INT_TIMER_THRESHOLD_OTHER 1000

#define WLAN_CFG_TX_RING_SIZE 512

/* Size the completion ring using following 2 parameters
 * - NAPI schedule latency (assuming 1 netdev competing for CPU)
 *   = 20 ms (2 jiffies)
 * - Worst case PPS requirement = 400K PPS
 *
 * Ring size = 20 * 400 = 8000
 * 8192 is nearest power of 2
 */
#define WLAN_CFG_TX_COMP_RING_SIZE 0x80000
#endif

#define WLAN_CFG_PER_PDEV_RX_RING_MIN 0
#define WLAN_CFG_PER_PDEV_RX_RING_MAX 0

#define WLAN_CFG_PER_PDEV_LMAC_RING_MIN 0
#define WLAN_CFG_PER_PDEV_LMAC_RING_MAX 1

#define WLAN_CFG_TX_RING_SIZE_MIN 512
#define WLAN_CFG_TX_RING_SIZE_MAX 2048

#define WLAN_CFG_TX_COMP_RING_SIZE_MIN 1024
#define WLAN_CFG_TX_COMP_RING_SIZE_MAX 0x80000

#define WLAN_CFG_NUM_TX_DESC_MIN  1024
#define WLAN_CFG_NUM_TX_DESC_MAX  0x320000

#define WLAN_CFG_NUM_TX_EXT_DESC_MIN  1024
#define WLAN_CFG_NUM_TX_EXT_DESC_MAX  0x80000

#define WLAN_CFG_INT_BATCH_THRESHOLD_TX_MIN 1
#define WLAN_CFG_INT_BATCH_THRESHOLD_TX_MAX 256

#define WLAN_CFG_INT_BATCH_THRESHOLD_RX_MIN 1
#define WLAN_CFG_INT_BATCH_THRESHOLD_RX_MAX 128

#define WLAN_CFG_INT_BATCH_THRESHOLD_OTHER_MIN 1
#define WLAN_CFG_INT_BATCH_THRESHOLD_OTHER_MAX 1

#define WLAN_CFG_INT_TIMER_THRESHOLD_TX_MIN 8
#define WLAN_CFG_INT_TIMER_THRESHOLD_TX_MAX 100

#define WLAN_CFG_INT_TIMER_THRESHOLD_RX_MIN 8
#define WLAN_CFG_INT_TIMER_THRESHOLD_RX_MAX 500

#define WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MIN 8
#define WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MAX 1000

#define WLAN_CFG_NSS_TX_COMP_RING_SIZE 0x1000
#define WLAN_CFG_NSS_TX_COMP_RING_SIZE_MIN 0x1000
#define WLAN_CFG_NSS_TX_COMP_RING_SIZE_MAX 0x1000

#ifdef QCA_LL_TX_FLOW_CONTROL_V2

/* Per vdev pools */
#define WLAN_CFG_NUM_TX_DESC_POOL	3
#define WLAN_CFG_NUM_TXEXT_DESC_POOL	3

#else /* QCA_LL_TX_FLOW_CONTROL_V2 */

#ifdef TX_PER_PDEV_DESC_POOL
#define WLAN_CFG_NUM_TX_DESC_POOL	MAX_PDEV_CNT
#define WLAN_CFG_NUM_TXEXT_DESC_POOL	MAX_PDEV_CNT

#else /* TX_PER_PDEV_DESC_POOL */

#define WLAN_CFG_NUM_TX_DESC_POOL 3
#define WLAN_CFG_NUM_TXEXT_DESC_POOL 3

#endif /* TX_PER_PDEV_DESC_POOL */
#endif /* QCA_LL_TX_FLOW_CONTROL_V2 */

#define WLAN_CFG_NUM_TXEXT_DESC_POOL_MIN 1
#define WLAN_CFG_NUM_TXEXT_DESC_POOL_MAX 4

#define WLAN_CFG_HTT_PKT_TYPE 2
#define WLAN_CFG_HTT_PKT_TYPE_MIN 2
#define WLAN_CFG_HTT_PKT_TYPE_MAX 2

#define WLAN_CFG_MAX_PEER_ID 64
#define WLAN_CFG_MAX_PEER_ID_MIN 64
#define WLAN_CFG_MAX_PEER_ID_MAX 64

#define WLAN_CFG_RX_DEFRAG_TIMEOUT 100
#define WLAN_CFG_RX_DEFRAG_TIMEOUT_MIN 100
#define WLAN_CFG_RX_DEFRAG_TIMEOUT_MAX 100

#define WLAN_CFG_NUM_TCL_DATA_RINGS 3
#define WLAN_CFG_NUM_TCL_DATA_RINGS_MIN 3
#define WLAN_CFG_NUM_TCL_DATA_RINGS_MAX 3

#define WLAN_CFG_NUM_REO_DEST_RING 4
#define WLAN_CFG_NUM_REO_DEST_RING_MIN 4
#define WLAN_CFG_NUM_REO_DEST_RING_MAX 4

#define WLAN_CFG_WBM_RELEASE_RING_SIZE 64
#define WLAN_CFG_WBM_RELEASE_RING_SIZE_MIN 64
#define WLAN_CFG_WBM_RELEASE_RING_SIZE_MAX 64

#define WLAN_CFG_TCL_CMD_RING_SIZE 32
#define WLAN_CFG_TCL_CMD_RING_SIZE_MIN 32
#define WLAN_CFG_TCL_CMD_RING_SIZE_MAX 32

#define WLAN_CFG_TCL_STATUS_RING_SIZE 32
#define WLAN_CFG_TCL_STATUS_RING_SIZE_MIN 32
#define WLAN_CFG_TCL_STATUS_RING_SIZE_MAX 32

#if defined(QCA_WIFI_QCA6290)
#define WLAN_CFG_REO_DST_RING_SIZE 1024
#else
#define WLAN_CFG_REO_DST_RING_SIZE 2048
#endif

#define WLAN_CFG_REO_DST_RING_SIZE_MIN 1024
#define WLAN_CFG_REO_DST_RING_SIZE_MAX 2048

#define WLAN_CFG_REO_REINJECT_RING_SIZE 32
#define WLAN_CFG_REO_REINJECT_RING_SIZE_MIN 32
#define WLAN_CFG_REO_REINJECT_RING_SIZE_MAX 32

#define WLAN_CFG_RX_RELEASE_RING_SIZE 1024
#define WLAN_CFG_RX_RELEASE_RING_SIZE_MIN 1024
#define WLAN_CFG_RX_RELEASE_RING_SIZE_MAX 1024

#define WLAN_CFG_REO_EXCEPTION_RING_SIZE 128
#define WLAN_CFG_REO_EXCEPTION_RING_SIZE_MIN 128
#define WLAN_CFG_REO_EXCEPTION_RING_SIZE_MAX 128

#define WLAN_CFG_REO_CMD_RING_SIZE 64
#define WLAN_CFG_REO_CMD_RING_SIZE_MIN 64
#define WLAN_CFG_REO_CMD_RING_SIZE_MAX 64

#define WLAN_CFG_REO_STATUS_RING_SIZE 128
#define WLAN_CFG_REO_STATUS_RING_SIZE_MIN 128
#define WLAN_CFG_REO_STATUS_RING_SIZE_MAX 128

#define WLAN_CFG_RXDMA_BUF_RING_SIZE 1024
#define WLAN_CFG_RXDMA_BUF_RING_SIZE_MIN 1024
#define WLAN_CFG_RXDMA_BUF_RING_SIZE_MAX 1024

#define WLAN_CFG_RXDMA_REFILL_RING_SIZE 4096
#define WLAN_CFG_RXDMA_REFILL_RING_SIZE_MIN 4096
#define WLAN_CFG_RXDMA_REFILL_RING_SIZE_MAX 4096

#define WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE 4096
#define WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE_MIN 4096
#define WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE_MAX 4096

#define WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE 2048
#define WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE_MIN 2048
#define WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE_MAX 2048

#define WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE 1024
#define WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE_MIN 1024
#define WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE_MAX 1024

#define WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE 4096
#define WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE_MIN 4096
#define WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE_MAX 4096

#define WLAN_CFG_RXDMA_ERR_DST_RING_SIZE 1024
#define WLAN_CFG_RXDMA_ERR_DST_RING_SIZE_MIN 1024
#define WLAN_CFG_RXDMA_ERR_DST_RING_SIZE_MAX 1024

/* DP INI Declerations */
#define CFG_DP_HTT_PACKET_TYPE \
		CFG_INI_UINT("dp_htt_packet_type", \
		WLAN_CFG_HTT_PKT_TYPE_MIN, \
		WLAN_CFG_HTT_PKT_TYPE_MAX, \
		WLAN_CFG_HTT_PKT_TYPE, \
		CFG_VALUE_OR_DEFAULT, "DP HTT packet type")

#define CFG_DP_INT_BATCH_THRESHOLD_OTHER \
		CFG_INI_UINT("dp_int_batch_threshold_other", \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MIN, \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MAX, \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER, \
		CFG_VALUE_OR_DEFAULT, "DP INT threshold Other")

#define CFG_DP_INT_BATCH_THRESHOLD_RX \
		CFG_INI_UINT("dp_int_batch_threshold_rx", \
		WLAN_CFG_INT_BATCH_THRESHOLD_RX_MIN, \
		WLAN_CFG_INT_BATCH_THRESHOLD_RX_MAX, \
		WLAN_CFG_INT_BATCH_THRESHOLD_RX, \
		CFG_VALUE_OR_DEFAULT, "DP INT threshold Rx")

#define CFG_DP_INT_BATCH_THRESHOLD_TX \
		CFG_INI_UINT("dp_int_batch_threshold_tx", \
		WLAN_CFG_INT_BATCH_THRESHOLD_TX_MIN, \
		WLAN_CFG_INT_BATCH_THRESHOLD_TX_MAX, \
		WLAN_CFG_INT_BATCH_THRESHOLD_TX, \
		CFG_VALUE_OR_DEFAULT, "DP INT threshold Tx")

#define CFG_DP_INT_TIMER_THRESHOLD_OTHER \
		CFG_INI_UINT("dp_int_timer_threshold_other", \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MIN, \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER_MAX, \
		WLAN_CFG_INT_TIMER_THRESHOLD_OTHER, \
		CFG_VALUE_OR_DEFAULT, "DP INT timer threshold Other")

#define CFG_DP_INT_TIMER_THRESHOLD_RX \
		CFG_INI_UINT("dp_int_timer_threshold_rx", \
		WLAN_CFG_INT_TIMER_THRESHOLD_RX_MIN, \
		WLAN_CFG_INT_TIMER_THRESHOLD_RX_MAX, \
		WLAN_CFG_INT_TIMER_THRESHOLD_RX, \
		CFG_VALUE_OR_DEFAULT, "DP INT timer threshold Rx")

#define CFG_DP_INT_TIMER_THRESHOLD_TX \
		CFG_INI_UINT("dp_int_timer_threshold_tx", \
		WLAN_CFG_INT_TIMER_THRESHOLD_TX_MIN, \
		WLAN_CFG_INT_TIMER_THRESHOLD_TX_MAX, \
		WLAN_CFG_INT_TIMER_THRESHOLD_TX, \
		CFG_VALUE_OR_DEFAULT, "DP INT timer threshold Tx")

#define CFG_DP_MAX_ALLOC_SIZE \
		CFG_INI_UINT("dp_max_alloc_size", \
		WLAN_CFG_MAX_ALLOC_SIZE_MIN, \
		WLAN_CFG_MAX_ALLOC_SIZE_MAX, \
		WLAN_CFG_MAX_ALLOC_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP Max Alloc Size")

#define CFG_DP_MAX_CLIENTS \
		CFG_INI_UINT("dp_max_clients", \
		WLAN_CFG_MAX_CLIENTS_MIN, \
		WLAN_CFG_MAX_CLIENTS_MAX, \
		WLAN_CFG_MAX_CLIENTS, \
		CFG_VALUE_OR_DEFAULT, "DP Max Clients")

#define CFG_DP_MAX_PEER_ID \
		CFG_INI_UINT("dp_max_peer_id", \
		WLAN_CFG_MAX_PEER_ID_MIN, \
		WLAN_CFG_MAX_PEER_ID_MAX, \
		WLAN_CFG_MAX_PEER_ID, \
		CFG_VALUE_OR_DEFAULT, "DP Max Peer ID")

#define CFG_DP_REO_DEST_RINGS \
		CFG_INI_UINT("dp_reo_dest_rings", \
		WLAN_CFG_NUM_REO_DEST_RING_MIN, \
		WLAN_CFG_NUM_REO_DEST_RING_MAX, \
		WLAN_CFG_NUM_REO_DEST_RING, \
		CFG_VALUE_OR_DEFAULT, "DP REO Destination Rings")

#define CFG_DP_TCL_DATA_RINGS \
		CFG_INI_UINT("dp_tcl_data_rings", \
		WLAN_CFG_NUM_TCL_DATA_RINGS_MIN, \
		WLAN_CFG_NUM_TCL_DATA_RINGS_MAX, \
		WLAN_CFG_NUM_TCL_DATA_RINGS, \
		CFG_VALUE_OR_DEFAULT, "DP TCL Data Rings")

#define CFG_DP_TX_DESC \
		CFG_INI_UINT("dp_tx_desc", \
		WLAN_CFG_NUM_TX_DESC_MIN, \
		WLAN_CFG_NUM_TX_DESC_MAX, \
		WLAN_CFG_NUM_TX_DESC, \
		CFG_VALUE_OR_DEFAULT, "DP Tx Descriptors")

#define CFG_DP_TX_EXT_DESC \
		CFG_INI_UINT("dp_tx_ext_desc", \
		WLAN_CFG_NUM_TX_EXT_DESC_MIN, \
		WLAN_CFG_NUM_TX_EXT_DESC_MAX, \
		WLAN_CFG_NUM_TX_EXT_DESC, \
		CFG_VALUE_OR_DEFAULT, "DP Tx Ext Descriptors")

#define CFG_DP_TX_EXT_DESC_POOLS \
		CFG_INI_UINT("dp_tx_ext_desc_pool", \
		WLAN_CFG_NUM_TXEXT_DESC_POOL_MIN, \
		WLAN_CFG_NUM_TXEXT_DESC_POOL_MAX, \
		WLAN_CFG_NUM_TXEXT_DESC_POOL, \
		CFG_VALUE_OR_DEFAULT, "DP Tx Ext Descriptors Pool")

#define CFG_DP_PDEV_RX_RING \
		CFG_INI_UINT("dp_pdev_rx_ring", \
		WLAN_CFG_PER_PDEV_RX_RING_MIN, \
		WLAN_CFG_PER_PDEV_RX_RING_MAX, \
		WLAN_CFG_PER_PDEV_RX_RING, \
		CFG_VALUE_OR_DEFAULT, "DP PDEV Rx Ring")

#define CFG_DP_PDEV_TX_RING \
		CFG_INI_UINT("dp_pdev_tx_ring", \
		WLAN_CFG_PER_PDEV_TX_RING_MIN, \
		WLAN_CFG_PER_PDEV_TX_RING_MAX, \
		WLAN_CFG_PER_PDEV_TX_RING, \
		CFG_VALUE_OR_DEFAULT, \
		"DP PDEV Tx Ring")

#define CFG_DP_RX_DEFRAG_TIMEOUT \
		CFG_INI_UINT("dp_rx_defrag_timeout", \
		WLAN_CFG_RX_DEFRAG_TIMEOUT_MIN, \
		WLAN_CFG_RX_DEFRAG_TIMEOUT_MAX, \
		WLAN_CFG_RX_DEFRAG_TIMEOUT, \
		CFG_VALUE_OR_DEFAULT, "DP Rx Defrag Timeout")

#define CFG_DP_TX_COMPL_RING_SIZE \
		CFG_INI_UINT("dp_tx_compl_ring_size", \
		WLAN_CFG_TX_COMP_RING_SIZE_MIN, \
		WLAN_CFG_TX_COMP_RING_SIZE_MAX, \
		WLAN_CFG_TX_COMP_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP Tx Completion Ring Size")

#define CFG_DP_TX_RING_SIZE \
		CFG_INI_UINT("dp_tx_ring_size", \
		WLAN_CFG_TX_RING_SIZE_MIN,\
		WLAN_CFG_TX_RING_SIZE_MAX,\
		WLAN_CFG_TX_RING_SIZE,\
		CFG_VALUE_OR_DEFAULT, "DP Tx Ring Size")

#define CFG_DP_NSS_COMP_RING_SIZE \
		CFG_INI_UINT("dp_nss_comp_ring_size", \
		WLAN_CFG_NSS_TX_COMP_RING_SIZE_MIN, \
		WLAN_CFG_NSS_TX_COMP_RING_SIZE_MAX, \
		WLAN_CFG_NSS_TX_COMP_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP NSS completion Ring Size")

#define CFG_DP_PDEV_LMAC_RING \
		CFG_INI_UINT("dp_pdev_lmac_ring", \
		WLAN_CFG_PER_PDEV_LMAC_RING_MIN, \
		WLAN_CFG_PER_PDEV_LMAC_RING_MAX, \
		WLAN_CFG_PER_PDEV_LMAC_RING, \
		CFG_VALUE_OR_DEFAULT, "DP pdev LMAC ring")

#define CFG_DP_BASE_HW_MAC_ID \
		CFG_INI_UINT("dp_base_hw_macid", \
		0, 1, 1, \
		CFG_VALUE_OR_DEFAULT, "DP Base HW Mac ID")

#define CFG_DP_LRO \
	CFG_INI_BOOL("LROEnable", WLAN_LRO_ENABLE, \
	"DP LRO Enable")

#define CFG_DP_RX_HASH \
	CFG_INI_BOOL("dp_rx_hash", true, \
	"DP Rx Hash")

#define CFG_DP_TSO \
	CFG_INI_BOOL("TSOEnable", false, \
	"DP TSO Enabled")

#define CFG_DP_NAPI \
	CFG_INI_BOOL("dp_napi_enabled", MCL_OR_WIN_VALUE(true, false), \
	"DP Napi Enabled")

#define CFG_DP_TCP_UDP_CKSUM_OFFLOAD \
	CFG_INI_BOOL("dp_tcp_udp_checksumoffload", true, \
	"DP TCP UDP Checksum Offload")

#define CFG_DP_DEFRAG_TIMEOUT_CHECK \
	CFG_INI_BOOL("dp_defrag_timeout_check", true, \
	"DP Defrag Timeout Check")

#define CFG_DP_WBM_RELEASE_RING \
		CFG_INI_UINT("dp_wbm_release_ring", \
		WLAN_CFG_WBM_RELEASE_RING_SIZE_MIN, \
		WLAN_CFG_WBM_RELEASE_RING_SIZE_MAX, \
		WLAN_CFG_WBM_RELEASE_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP WBM Release Ring")

#define CFG_DP_TCL_CMD_RING \
		CFG_INI_UINT("dp_tcl_cmd_ring", \
		WLAN_CFG_TCL_CMD_RING_SIZE_MIN, \
		WLAN_CFG_TCL_CMD_RING_SIZE_MAX, \
		WLAN_CFG_TCL_CMD_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP TCL command ring")

#define CFG_DP_TCL_STATUS_RING \
		CFG_INI_UINT("dp_tcl_status_ring",\
		WLAN_CFG_TCL_STATUS_RING_SIZE_MIN, \
		WLAN_CFG_TCL_STATUS_RING_SIZE_MAX, \
		WLAN_CFG_TCL_STATUS_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP TCL status ring")

#define CFG_DP_REO_REINJECT_RING \
		CFG_INI_UINT("dp_reo_reinject_ring", \
		WLAN_CFG_REO_REINJECT_RING_SIZE_MIN, \
		WLAN_CFG_REO_REINJECT_RING_SIZE_MAX, \
		WLAN_CFG_REO_REINJECT_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP REO reinject ring")

#define CFG_DP_RX_RELEASE_RING \
		CFG_INI_UINT("dp_rx_release_ring", \
		WLAN_CFG_RX_RELEASE_RING_SIZE_MIN, \
		WLAN_CFG_RX_RELEASE_RING_SIZE_MAX, \
		WLAN_CFG_RX_RELEASE_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP Rx release ring")

#define CFG_DP_REO_EXCEPTION_RING \
		CFG_INI_UINT("dp_reo_exception_ring", \
		WLAN_CFG_REO_EXCEPTION_RING_SIZE_MIN, \
		WLAN_CFG_REO_EXCEPTION_RING_SIZE_MAX, \
		WLAN_CFG_REO_EXCEPTION_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP REO exception ring")

#define CFG_DP_REO_CMD_RING \
		CFG_INI_UINT("dp_reo_cmd_ring", \
		WLAN_CFG_REO_CMD_RING_SIZE_MIN, \
		WLAN_CFG_REO_CMD_RING_SIZE_MAX, \
		WLAN_CFG_REO_CMD_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP REO command ring")

#define CFG_DP_REO_STATUS_RING \
		CFG_INI_UINT("dp_reo_status_ring", \
		WLAN_CFG_REO_STATUS_RING_SIZE_MIN, \
		WLAN_CFG_REO_STATUS_RING_SIZE_MAX, \
		WLAN_CFG_REO_STATUS_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP REO status ring")

#define CFG_DP_RXDMA_BUF_RING \
		CFG_INI_UINT("dp_rxdma_buf_ring", \
		WLAN_CFG_RXDMA_BUF_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_BUF_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_BUF_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA buffer ring")

#define CFG_DP_RXDMA_REFILL_RING \
		CFG_INI_UINT("dp_rxdma_refill_ring", \
		WLAN_CFG_RXDMA_REFILL_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_REFILL_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_REFILL_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA refilll ring")

#define CFG_DP_RXDMA_MONITOR_BUF_RING \
		CFG_INI_UINT("dp_rxdma_monitor_buf_ring", \
		WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_MONITOR_BUF_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA monitor buffer ring")

#define CFG_DP_RXDMA_MONITOR_DST_RING \
		CFG_INI_UINT("dp_rxdma_monitor_dst_ring", \
		WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_MONITOR_DST_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA monitor destination ring")

#define CFG_DP_RXDMA_MONITOR_STATUS_RING \
		CFG_INI_UINT("dp_rxdma_monitor_status_ring", \
		WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_MONITOR_STATUS_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA monitor status ring")

#define CFG_DP_RXDMA_MONITOR_DESC_RING \
		CFG_INI_UINT("dp_rxdma_monitor_desc_ring", \
		WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_MONITOR_DESC_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "DP RXDMA monitor destination ring")

#define CFG_DP_RXDMA_ERR_DST_RING \
		CFG_INI_UINT("dp_rxdma_err_dst_ring", \
		WLAN_CFG_RXDMA_ERR_DST_RING_SIZE_MIN, \
		WLAN_CFG_RXDMA_ERR_DST_RING_SIZE_MAX, \
		WLAN_CFG_RXDMA_ERR_DST_RING_SIZE, \
		CFG_VALUE_OR_DEFAULT, "RXDMA err destination ring")

#define CFG_DP \
		CFG(CFG_DP_HTT_PACKET_TYPE) \
		CFG(CFG_DP_INT_BATCH_THRESHOLD_OTHER) \
		CFG(CFG_DP_INT_BATCH_THRESHOLD_RX) \
		CFG(CFG_DP_INT_BATCH_THRESHOLD_TX) \
		CFG(CFG_DP_INT_TIMER_THRESHOLD_OTHER) \
		CFG(CFG_DP_INT_TIMER_THRESHOLD_RX) \
		CFG(CFG_DP_INT_TIMER_THRESHOLD_TX) \
		CFG(CFG_DP_MAX_ALLOC_SIZE) \
		CFG(CFG_DP_MAX_CLIENTS) \
		CFG(CFG_DP_MAX_PEER_ID) \
		CFG(CFG_DP_REO_DEST_RINGS) \
		CFG(CFG_DP_TCL_DATA_RINGS) \
		CFG(CFG_DP_TX_DESC) \
		CFG(CFG_DP_TX_EXT_DESC) \
		CFG(CFG_DP_TX_EXT_DESC_POOLS) \
		CFG(CFG_DP_PDEV_RX_RING) \
		CFG(CFG_DP_PDEV_TX_RING) \
		CFG(CFG_DP_RX_DEFRAG_TIMEOUT) \
		CFG(CFG_DP_TX_COMPL_RING_SIZE) \
		CFG(CFG_DP_TX_RING_SIZE) \
		CFG(CFG_DP_NSS_COMP_RING_SIZE) \
		CFG(CFG_DP_PDEV_LMAC_RING) \
		CFG(CFG_DP_BASE_HW_MAC_ID) \
		CFG(CFG_DP_LRO) \
		CFG(CFG_DP_RX_HASH) \
		CFG(CFG_DP_TSO) \
		CFG(CFG_DP_NAPI) \
		CFG(CFG_DP_TCP_UDP_CKSUM_OFFLOAD) \
		CFG(CFG_DP_DEFRAG_TIMEOUT_CHECK) \
		CFG(CFG_DP_WBM_RELEASE_RING) \
		CFG(CFG_DP_TCL_CMD_RING) \
		CFG(CFG_DP_TCL_STATUS_RING) \
		CFG(CFG_DP_REO_REINJECT_RING) \
		CFG(CFG_DP_RX_RELEASE_RING) \
		CFG(CFG_DP_REO_EXCEPTION_RING) \
		CFG(CFG_DP_REO_CMD_RING) \
		CFG(CFG_DP_REO_STATUS_RING) \
		CFG(CFG_DP_RXDMA_BUF_RING) \
		CFG(CFG_DP_RXDMA_REFILL_RING) \
		CFG(CFG_DP_RXDMA_MONITOR_BUF_RING) \
		CFG(CFG_DP_RXDMA_MONITOR_DST_RING) \
		CFG(CFG_DP_RXDMA_MONITOR_STATUS_RING) \
		CFG(CFG_DP_RXDMA_MONITOR_DESC_RING) \
		CFG(CFG_DP_RXDMA_ERR_DST_RING)

#endif /* _CFG_DP_H_ */
