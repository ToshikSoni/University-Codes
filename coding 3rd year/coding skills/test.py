from scapy.all import sniff, IP
import logging
from collections import defaultdict
import time

# Setup logging
logging.basicConfig(
    filename='ids.log',
    level=logging.INFO,
    format='%(asctime)s - %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S'
)

# Dictionary to count IP occurrences
ip_count = defaultdict(int)
# Thresholds
THRESHOLD = 10
TIME_WINDOW = 60  # 1 minute
SCAN_THRESHOLD = 100  # Number of packets in a short time indicating a scan

# Store timestamps of incoming packets
ip_timestamps = defaultdict(list)

def detect_scan(ip):
    now = time.time()
    ip_timestamps[ip].append(now)
    # Remove timestamps older than TIME_WINDOW
    ip_timestamps[ip] = [t for t in ip_timestamps[ip] if now - t <= TIME_WINDOW]
    if len(ip_timestamps[ip]) > SCAN_THRESHOLD:
        return True
    return False

def packet_callback(packet):
    if IP in packet:
        src_ip = packet[IP].src
        ip_count[src_ip] += 1

        # Detect port scanning
        if detect_scan(src_ip):
            logging.warning(f"Port scan detected from IP: {src_ip}")
            print(f"Port scan detected from IP: {src_ip}")

        # Detect unusual traffic
        if ip_count[src_ip] > THRESHOLD:
            logging.warning(f"Unusual traffic detected from IP: {src_ip}")
            print(f"Unusual traffic detected from IP: {src_ip}")
            ip_count[src_ip] = 0  # Reset count to avoid repetitive logging

# Start sniffing
print("Starting IDS...")
sniff(prn=packet_callback, store=0)