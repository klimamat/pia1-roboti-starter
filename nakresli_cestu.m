function nakresli_cestu(soubor_cesta)
  cesta=load(soubor_cesta);
  cesta_r=cesta+0.2*(rand(size(cesta,1),2) - 0.5);
  hold on;
  xlim([-0.5,19.5]);
  ylim([-0.5,9.5]);
  plot(cesta_r(:,1),cesta_r(:,2));
  plot(cesta(1,1),cesta(1,2),'gx');
end