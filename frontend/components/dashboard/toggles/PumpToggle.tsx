import GenericToggle from './GenericToggle';

type Props = {
  enabled: boolean
  onClick: any
}

const PumpToggle = ({
  enabled,
  onClick
}: Props) => {
  return (  
    <GenericToggle title="Pump" isOn={enabled} onClick={onClick}>
      <svg 
        xmlns="http://www.w3.org/2000/svg" 
        className="h-9 w-9 fill-current" 
        viewBox="0 0 24 24">
          <path d="M12 16c2.947 0 5.333-2.365 5.333-5.284 0-2.917-2.087-5.918-5.333-10.716-3.246 4.798-5.332 7.799-5.332 10.716 0 2.919 2.385 5.284 5.332 5.284zm-.018-12.587c.311.484.685 1.325.685 2.213 0 2.606-2.667 3.033-2.667 1.447 0-1.088 1.326-2.696 1.982-3.66zm.018 16.587c-2.367 0-5.711-.614-7.285-2.356.473-.294 1.15-.61 2.021-.889.923.589 2.702 1.245 5.264 1.245s4.341-.656 5.265-1.245c.87.278 1.548.595 2.022.889-1.574 1.742-4.92 2.356-7.287 2.356zm11.997-2c0 3.313-5.37 6-11.997 6-6.625 0-11.997-2.687-11.997-6l.003-.126c.043-1.009.615-1.921 1.505-2.398s1.965-.448 2.829.074l.023.014c-1.513.763-2.361 1.678-2.361 2.436 0 1.631 3.895 4 9.998 4s9.998-2.369 9.998-4c0-.757-.847-1.671-2.358-2.436l.021-.012c.877-.529 1.969-.548 2.864-.052s1.458 1.434 1.472 2.458v.042zm-4.999-4.031c1.453-1.406 3.064-.182 4.402-1.477.418-.403.603-.902.603-1.384 0-1.279-1.481-2.261-3.021-1.436-1.234.661-1.921 2.349-1.984 4.297zm.178-5.067c.63-1.037 1.749-.57 2.329-1.524.688-1.133-.729-2.29-1.829-1.269-.615.57-.76 1.654-.5 2.793zm-16.153.77c-1.539-.825-3.021.157-3.021 1.436 0 .482.185.98.602 1.384 1.338 1.295 2.95.071 4.402 1.477-.062-1.948-.748-3.636-1.983-4.297zm1.307-3.563c-1.1-1.021-2.518.136-1.83 1.269.58.954 1.699.487 2.33 1.524.259-1.139.115-2.223-.5-2.793z"/>
      </svg>
    </GenericToggle>
  ) 
}

export default PumpToggle