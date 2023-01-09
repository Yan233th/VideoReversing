using System.Runtime.InteropServices;

internal static class MainWindowHelpers
{
    [DllImport ("VideoReversingDLL.dll")]
    static extern string GetFileName (string input);
}