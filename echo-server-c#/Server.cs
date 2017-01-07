using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace ComputerNetworks
{
    class EchoServer
    {
        private const int Port = 13301;

        static void Main()
        {
            var ipHostInfo = Dns.GetHostEntry(Dns.GetHostName());
            var ipAddress = ipHostInfo.AddressList[0];
            var localEndPoint = new IPEndPoint(ipAddress, Port);

            var listeningSocket = new Socket(
                AddressFamily.InterNetwork,
                SocketType.Stream,
                ProtocolType.Tcp
            );

            try
            {
                listeningSocket.Bind(localEndPoint);
                listeningSocket.Listen(5);
                Console.WriteLine($"Listening on {Port}");

                while (true)
                {
                    var connectedSocket = listeningSocket.Accept();

                    Console.WriteLine("Client connected.");

                    var buffer = new byte[1024];
                    var data = string.Empty;
                    int bytesRec;

                    bytesRec = connectedSocket.Receive(buffer);
                    data += Encoding.ASCII.GetString(buffer, 0, bytesRec);

                    Console.WriteLine($"Message received: {data}");
                    connectedSocket.Send(Encoding.ASCII.GetBytes(data));
                    Console.WriteLine($"Message sent: {data}");

                    connectedSocket.Shutdown(SocketShutdown.Both);
                    connectedSocket.Close();

                    Console.WriteLine("Client disconnected.");
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
        }
    }
}
