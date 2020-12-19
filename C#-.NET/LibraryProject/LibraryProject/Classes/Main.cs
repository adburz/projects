using System;
using System.Diagnostics;

using LibraryProject.Classes.Library;
using System.Windows;
using System.Windows.Media.Imaging;


namespace LibraryProject
{
    static public class Main
    {
        static public Library Library;
        static public ExceptionHandler ExceptionHandler;
        static Main()
        {
            ExceptionHandler = new ExceptionHandler();  //we have to initialize it first, because it handles all errors from next classes
            Library = new Library();          
        }

        static public void SetBooksIcon(Window _window)
        {
            // string path = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, @"LibraryProject\Icons");
            try
            {
                Uri iconUri = new Uri(@"E:\OneDrive\OneDrive - Politechnika Śląska\STUDIA\SEM 4\PK4\REPO\Projekt\LibraryProject\LibraryProject\Icons\books1.ico", UriKind.RelativeOrAbsolute);
                _window.Icon = BitmapFrame.Create(iconUri);

            }
            catch(Exception e)
            {
                Debug.WriteLine(e.Message);
                _window.Icon = null;        //if exception - setting default icon (null)
            }
        }
    }
}
