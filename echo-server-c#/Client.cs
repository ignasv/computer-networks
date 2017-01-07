using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ComputerNetworks
{
    class EchoClient
    {
        private const int Port = 13301;

        static void Main()
        {
            try
            {
                var ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
                var ipAddress = ipHostInfo.AddressList[0];
                var remoteEndPoint = new IPEndPoint(ipAddress, Port);

                var sender = new Socket(
                    AddressFamily.InterNetwork,
                    SocketType.Stream,
                    ProtocolType.Tcp
                );

                sender.Connect(remoteEndPoint);
                Console.WriteLine("Connected. Enter your message:");
                var message = Console.ReadLine();

                sender.Send(Encoding.ASCII.GetBytes(message));
                Console.WriteLine($"Message sent: {message}");
                
                var buffer = new byte[1024];                    
                var data = string.Empty;
                int bytesRec;

                while((bytesRec = sender.Receive(buffer)) > 0) {
                    data += Encoding.ASCII.GetString(buffer, 0, bytesRec);
                }
                Console.WriteLine($"Message received: {data}");
                
                sender.Shutdown(SocketShutdown.Both);
                sender.Close();

                Console.WriteLine("Disconnected");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }
    }
}