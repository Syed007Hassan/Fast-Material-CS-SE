resource "azurerm_resource_group" "lab_rg" {
  name     = "lab1"
  location = "westus"

  tags = {
    "key" = "lab"
  }

}

resource "azurerm_virtual_network" "lab_rg" {
  name                = "lab_rg-network"
  address_space       = ["10.0.0.0/16"]
  location            = azurerm_resource_group.lab_rg.location
  resource_group_name = azurerm_resource_group.lab_rg.name
}

resource "azurerm_subnet" "lab_rg" {
  name                 = "internal"
  resource_group_name  = azurerm_resource_group.lab_rg.name
  virtual_network_name = azurerm_virtual_network.lab_rg.name
  address_prefixes     = ["10.0.2.0/24"]
}


resource "azurerm_public_ip" "lab_rg" {
  name                = "lab_rg-ip"
  location            = azurerm_resource_group.lab_rg.location
  resource_group_name = azurerm_resource_group.lab_rg.name
  allocation_method   = "Dynamic"

  tags = {
    environment = "Production"
  }

}

resource "azurerm_network_interface" "lab_rg" {
  name                = "lab_rg-nic"
  location            = azurerm_resource_group.lab_rg.location
  resource_group_name = azurerm_resource_group.lab_rg.name

  ip_configuration {
    name                          = "internal"
    subnet_id                     = azurerm_subnet.lab_rg.id
    private_ip_address_allocation = "Dynamic"
    public_ip_address_id          = azurerm_public_ip.lab_rg.id
  }
}

resource "azurerm_linux_virtual_machine" "lab_rg" {
  name                = "labrgmachine"
  resource_group_name = azurerm_resource_group.lab_rg.name
  location            = azurerm_resource_group.lab_rg.location
  size                = "Standard_F2"
  admin_username      = "adminuser"
  network_interface_ids = [
    azurerm_network_interface.lab_rg.id,
  ]

  admin_ssh_key {
    username   = "adminuser"
    public_key = file("vm.pub")
  }

  os_disk {
    caching              = "ReadWrite"
    storage_account_type = "Standard_LRS"
  }

  source_image_reference {
    publisher = "Canonical"
    offer     = "0001-com-ubuntu-server-jammy"
    sku       = "22_04-lts"
    version   = "latest"
  }
}

