   M S B A M L   `   `   `  ����I  ELibraryProject, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null{Bclr-namespace:LibraryProject.Windows.LibraryMainWindow.Views.Admin4LibraryProject.Windows.LibraryMainWindow.Views.Admin  5      K    ELibraryProject.Windows.LibraryMainWindow.Views.Admin.Users_MainWindow   5      R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      TlocalBclr-namespace:LibraryProject.Windows.LibraryMainWindow.Views.Admin     5      .��5
      ��   �� Padding$	   10q�6   ._�5   
   �� 
�������.+�5      �  � RowDefinitions 5      �� 5      $��2* �6$   �� 5      $��8* �6$   .+�5      � $��0��6    � ColumnDefinitions 5      �� 5      $��* �6+   �� 5      $��* �6+   �� 5      $��* �6+   �� 5      $��* �6+   .+�5      �� $��5q�6!   $��0��6-   .+�5      �� $��Search Name:��6    �� 5      -   5        $��Name_TextBlock��5   "   $�� 4 0 4 0q�68   6K   �� 5       $��Search Surname:��6    �� 5!      -   5        $��Surname_TextBlock��5!   "   $�� 4 0 4 4q�6;   6N   5"      �� 5&      $��5q�6!   $��1��6,   .+�5'      �� $��Search Pesel:��6    �� 5(      -   5        $��Pesel_TextBlock��5(   "   $�� 4 0 4 0q�69   6L   �� 5)      $��Search Email��6    �� 5*      -   5        $��Email_TextBlock��5*   "   $�� 4 0 4 4q�69   6L   5+      �� 5.      $��
15 41 15 0q�6!   $��2��65   .+�5/      �� -   5        $��4q�5/   !   $��Add user��6-   6@   �� 50      -   5        $��4q�50   !   $��
Scope user��6-   6B   51      �� 54      $��
15 41 15 0q�6!   $��3��65   .+�55      �� -   5        $��4q�55   :   $��Delete user��6E   �� 56      -   5        $��4q�56   5   $��Refresh List��6@   57      58      &   System.Windows.Controls.DataGrid  5<      -	   5        $��users_DataGrid��5<   ,   $��1��6   $��
10 30 10 0q�6B      AutoGenerateColumns .     CanUserAddRows .  $	��324��5=   6    � 	Resources 5>       �� Color��%X   (��       5?   .   * SystemColors.HighlightBrushKey+)�� 6   $ #C80000��5@   .   5A         Columns 5B      0  *System.Windows.Controls.DataGridTextColumn  5C      ,  &System.Windows.Controls.DataGridColumn   Header$ ID��61   1  +System.Windows.Controls.DataGridBoundColumn	   Binding	 6=   �� 
 �� Path$
 UserID�  5D      $
 Name��61   	 6?   �� $

 Name�  5E      $ Surname��61   	 6B   �� $
 Surname�  5F      $ PESEL��61   	 6@   �� $
 Pesel�  5G      $ E-mail��61   	 6A   �� $
 Email�  5H      $ 
Hire count��61      
IsReadOnly . 	 6W   �� $
 	HireCount�  5I      $ Expired count��61    . 	 6Z   �� $
 ExpiredCount�  5J      $
 Role��61   	 6?   �� $
 SRole�5L      5P      5S      5T      5U      