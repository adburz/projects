using System.Windows;

namespace LibraryProject.Windows.LibraryMainWindow.Views.Admin.ShelfsTab
{
    /// <summary>
    /// Interaction logic for AddEntity.xaml
    /// </summary>
    public partial class AddEntity : Window
    {
        public AddEntity()
        {
            InitializeComponent();
            EntityType.Content = new AddBook_Page();
            Main.SetBooksIcon(this);
            this.Show();
        }

        private void AddBook_Click(object sender, RoutedEventArgs e)
        {
            EntityType.Content = new AddBook_Page();
        }

        private void AddMagazine_Click(object sender, RoutedEventArgs e)
        {
            EntityType.Content = new AddMagazine_Page();
        }
    }
}
