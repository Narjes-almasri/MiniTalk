# MiniTalk

## 🧠 About  

The **Minitalk** project implements a simple communication protocol between two processes using **UNIX signals**.  

The communication occurs over a single “virtual wire” created by signal transmission:  
- The **speaker (client)** sends a message by transmitting a sequence of signals.  
- The **listener (server)** receives and interprets these signals to reconstruct the original message.  

The project’s main goal is to understand **low-level interprocess communication (IPC)** and synchronization using only `SIGUSR1` and `SIGUSR2`.

<p align="center">
  <img src="94b12faa-20c1-4645-bb59-16b377be2423.png" alt="Minitalk communication protocol diagram" width="700">
</p>

---

## 📜 Mandatory Requirements  

- Create two executables: `server` and `client`.  
- The **client** must send a string as a message to the **server**, identified by its process ID (PID).  
- The **server** displays the received message on the standard output.  
- Use **only** `SIGUSR1` and `SIGUSR2`.

---

## 💎 Bonus Features  

- Implement an acknowledgment system so the client knows the message was received.  
- Support **Unicode characters** for extended text compatibility.

---

## ⚙️ Allowed Functions  

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)  
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)  
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)  
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)  
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)  
- [`sigemptyset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)  
- [`sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)  
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)  
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)  
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)  
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)  
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)  
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

---

## 🧩 Compilation  

1. Clone the repository with its submodules:  
   ```bash
   git clone https://github.com/Narjes-almasri/MiniTalk.git
   cd MiniTalk
   make
