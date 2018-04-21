# -*- mode: ruby -*-
# vi: set ft=ruby :

VAGRANTFILE_API_VERSION = '2'

Vagrant.configure(VAGRANTFILE_API_VERSION) do |config|
  config.vm.box = 'ubuntu/artful64'  # 17.10

  config.vm.provider :virtualbox do |vb|
    vb.customize ["modifyvm", :id, "--memory", "1024"]
    vb.customize ["modifyvm", :id, "--cpuexecutioncap", "30"]
    vb.customize ["modifyvm", :id, "--cpus", "1"]
  end

  config.vm.network :forwarded_port, guest: 5000, host: 5000 # gdbgui port

  config.vm.provision :shell, path: 'provision/os_setup.sh', keep_color: true
end
