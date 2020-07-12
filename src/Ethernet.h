#ifndef ethernet_h
#define ethernet_h

#include <inttypes.h>
//#include "w5100.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetServer.h"
#include "Dhcp.h"

#define MAX_SOCK_NUM 4
#define _OPEN_TIMEOUT 4500L
#define _DNS_WAIT_RESP_TIMEOUT 4000L
#define _DNS_RETRIES 3










enum EthernetLinkStatus {
	Unknown,
	LinkON,
	LinkOFF
};











void ethernetIdle(void);

class EthernetClass {
private:
  IPAddress _dnsServerAddress;
  DhcpClass* _dhcp;
public:
  static uint8_t _state[MAX_SOCK_NUM];
  static uint16_t _server_port[MAX_SOCK_NUM];
  // Initialise the Ethernet shield to use the provided MAC address and gain the rest of the
  // configuration through DHCP.
  // Returns 0 if the DHCP configuration failed, and 1 if it succeeded
  int begin(uint8_t *mac_address, unsigned long timeout = 60000, unsigned long responseTimeout = 4000);
  void begin(uint8_t *mac_address, IPAddress local_ip);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
  void begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
  int maintain();
  static EthernetLinkStatus linkStatus();

  IPAddress localIP();
  IPAddress subnetMask();
  IPAddress gatewayIP();
  IPAddress dnsServerIP();

  friend class EthernetClient;
  friend class EthernetServer;
};

extern EthernetClass Ethernet;

#endif
